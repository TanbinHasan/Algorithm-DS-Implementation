#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>
class SegmentTree {
  int n;
  vector<T> t, lazy;  // tree value, propagation value
 public:
  T combine(T x, T y) {  // change here
    return min(x, y);
  }
  void build(int at, int l, int r) {
    if (l == r) return void(t[at] = 0);  // change here
    int m = (l + r) >> 1;
    build(at << 1, l, m);
    build(at << 1 | 1, m + 1, r);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  SegmentTree(int _n) : n(_n), t(4 * n), lazy(4 * n, -1) { build(1, 0, n - 1); }

  void propagate(int at, int l, int r) {  // change here
    if (lazy[at] == -1) return;
    t[at] = lazy[at];
    if (l != r) lazy[at << 1] = lazy[at];
    if (l != r) lazy[at << 1 | 1] = lazy[at];
    lazy[at] = -1;
  }

  void update(int at, int l, int r, int L, int R, T val) {
    propagate(at, l, r);
    if (l > R || r < L) return;  // not in range
    if (L <= l && r <= R) {      // completely inside the range
      lazy[at] = val;
      propagate(at, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(at << 1, l, m, L, R, val);
    update(at << 1 | 1, m + 1, r, L, R, val);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

  T query(int at, int l, int r, int L, int R) {
    propagate(at, l, r);
    if (L <= l && r <= R) return t[at];
    int m = (l + r) >> 1;
    if (m >= R) return query(at << 1, l, m, L, R);
    if (m < L) return query(at << 1 | 1, m + 1, r, L, R);
    return combine(query(at << 1, l, m, L, R), query(at << 1 | 1, m + 1, r, L, R));
  }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  int n, q;
  cin >> n >> q;
  SegmentTree<i64> st(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.update(l, r - 1, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r - 1) << '\n';
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalculation();
  int tt = 1;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const i64 INF = (i64)1e18;

template <class T>
class SegmentTree {
  int n;
  vector<T> t, lazy1, lazy2;  // tree value, propagation value
 public:
  T combine(T x, T y) {  // change here
    return x + y;
  }
  void build(int at, int l, int r) {
    if (l == r) return void(t[at] = 0);  // change here
    int m = (l + r) >> 1;
    build(at << 1, l, m);
    build(at << 1 | 1, m + 1, r);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  SegmentTree(int _n) : n(_n), t(4 * n), lazy1(4 * n, INF), lazy2(4 * n) { build(1, 0, n - 1); }

  void propagate(int at, int l, int r) {
    if (lazy1[at] != INF) {
      t[at] = lazy1[at] * (r - l + 1);
      if (l != r) {
        lazy1[at << 1] = lazy1[at];
        lazy1[at << 1 | 1] = lazy1[at];
        lazy2[at << 1] = lazy2[at << 1 | 1] = 0;
      }
    }
    if (lazy2[at]) {
      t[at] += lazy2[at] * (r - l + 1);
      if (l != r) {
        lazy2[at << 1] += lazy2[at];
        lazy2[at << 1 | 1] += lazy2[at];
      }
    }
    lazy1[at] = INF, lazy2[at] = 0;
  }

  void update(int at, int l, int r, int L, int R, T val, int type) {
    propagate(at, l, r);
    if (l > R || r < L) return;  // not in range
    if (L <= l && r <= R) {      // completely inside the range
      if (type == 1) lazy1[at] = val, lazy2[at] = 0;
      else lazy2[at] += val;
      propagate(at, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(at << 1, l, m, L, R, val, type);
    update(at << 1 | 1, m + 1, r, L, R, val, type);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  void update(int l, int r, int val, int type) { update(1, 0, n - 1, l, r, val, type); }

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
    if (t == 1 || t == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      st.update(l, r - 1, v, t);
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
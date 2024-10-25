#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>
class SegmentTree {
  int n;
  vector<T> t, lazy;  // tree value, propagation value
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
  SegmentTree(int _n) : n(_n), t(4 * n), lazy(4 * n) { build(1, 0, n - 1); }

  void propagate(int at, int l, int r) {  // change here
    if (!lazy[at]) return;
    t[at] = (r - l + 1) - t[at];
    if (l != r) {
      lazy[at << 1] ^= 1;
      lazy[at << 1 | 1] ^= 1;
    }
    lazy[at] = 0;
  }

  void update(int at, int l, int r, int L, int R) {
    propagate(at, l, r);
    if (l > R || r < L) return;  // not in range
    if (L <= l && r <= R) {      // completely inside the range
      lazy[at] = 1;
      propagate(at, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(at << 1, l, m, L, R);
    update(at << 1 | 1, m + 1, r, L, R);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  void update(int l, int r) { update(1, 0, n - 1, l, r); }

  T find(int k, int at, int l, int r) {
    propagate(at, l, r);
    if (l == r) return l;
    int m = l + (r - l) / 2LL;
    propagate(at << 1, l, m);
    propagate(at << 1 | 1, m + 1, r);
    T sl = t[at << 1]; // left subtree sum
    if (sl >= k + 1) return find(k, at << 1, l, m);
    return find(k - sl, at << 1 | 1, m + 1, r);
  }
  T find(int k) { return find(k, 1, 0, n - 1); }
};

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  int n, m;
  cin >> n >> m;
  SegmentTree<int> st(n);
  while (m--) {
    int t;
    cin >> t;
    if (t == 2) {
      int k;
      cin >> k;
      cout << st.find(k) << '\n';
    } else {
      int l, r;
      cin >> l >> r;
      st.update(l, r - 1);
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
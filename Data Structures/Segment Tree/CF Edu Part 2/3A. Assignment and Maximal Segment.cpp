#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const i64 INF = (i64)1e18;

template <class T>
struct node {
  T tot, pref, suf, mx;
};

template <class T>
class SegmentTree {
  int n;
  vector<T> t;  // tree value, propagation value
  vector<i64> lazy;
 public:
  T combine(T x, T y) {  // change here
    T r;
    r.tot = x.tot + y.tot;
    r.pref = max(x.pref, x.tot + y.pref);
    r.suf = max(x.suf + y.tot, y.suf);
    r.mx = max({x.mx, y.mx, x.suf + y.pref});
    return r;
  }
  void build(int at, int l, int r) {
    if (l == r) return void(t[at] = {0, 0, 0, 0});  // change here
    int m = (l + r) >> 1;
    build(at << 1, l, m);
    build(at << 1 | 1, m + 1, r);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  SegmentTree(int _n) : n(_n), t(4 * n), lazy(4 * n, INF) { build(1, 0, n - 1); }

  void propagate(int at, int l, int r) {  // change here
    if (lazy[at] == INF) return;
    t[at] = {lazy[at] * (r - l + 1), lazy[at] * (r - l + 1), lazy[at] * (r - l + 1), lazy[at] * (r - l + 1)};
    t[at] = {t[at].tot, max(0LL, t[at].pref), max(0LL, t[at].suf), max(0LL, t[at].mx)};
    if (l != r) lazy[at << 1] = lazy[at];
    if (l != r) lazy[at << 1 | 1] = lazy[at];
    lazy[at] = INF;
  }

  void update(int at, int l, int r, int L, int R, int val) {
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
  SegmentTree<node<i64>> st(n);
  while (q--) {
    int l, r, v;
    cin >> l >> r >> v;
    st.update(l, r - 1, v);
    cout << st.query(0, n - 1).mx << '\n';
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
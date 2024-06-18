/*
  17.06.2024 00:20:28
  The segment with the maximum sum
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>
struct node {
  T tot, pref, suf, mx;
};

template <class T>
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T x, T y) {  // change here
    T r;
    r.tot = x.tot + y.tot;
    r.pref = max(x.pref, x.tot + y.pref);
    r.suf = max(x.suf + y.tot, y.suf);
    r.mx = max({x.mx, y.mx, x.suf + y.pref});
    return r;
  }
  void build(vector<int>& a, int u, int l, int r) {
    if (l == r) return void(t[u] = {a[l], max(0, a[l]), max(0, a[l]), max(0, a[l])});  // change here
    int m = l + (r - l) / 2;
    build(a, u << 1, l, m);
    build(a, u << 1 | 1, m + 1, r);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  SegmentTree(vector<int> a) : n((int)a.size()) {
    t.resize(4 * n);
    build(a, 1, 0, n - 1);
  }

  void update(int u, int l, int r, int p, int val) {
    if (l == r) return void(t[u] = {val, max(0, val), max(0, val), max(0, val)});  // change here
    int m = l + (r - l) / 2;
    if (p <= m) update(u << 1, l, m, p, val);
    else update(u << 1 | 1, m + 1, r, p, val);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  void update(int p, int val) { update(1, 0, n - 1, p, val); }
  T query(int u, int l, int r, int L, int R) {
    if (L <= l && r <= R) return t[u];
    int m = l + (r - l) / 2;
    if (R <= m) return query(u << 1, l, m, L, R);
    if (m < L) return query(u << 1 | 1, m + 1, r, L, R);
    return combine(query(u << 1, l, m, L, R), query(u << 1 | 1, m + 1, r, L, R));
  }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  SegmentTree<node<i64>> st(a);
  cout << st.query(0, n - 1).mx << '\n';
  while (q--) {
    int p, val;
    cin >> p >> val;
    st.update(p, val);
    cout << st.query(0, n - 1).mx << '\n';
  }
  return 0;
}
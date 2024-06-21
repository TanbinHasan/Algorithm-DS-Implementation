/*
  16.06.2024 00:33:22
  Finding Minimum with Number of times it appears  
*/
// 15.06.2024 14:22:27
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>  // return type
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T x, T y) {  // change here
    if (x[0] < y[0]) return x;
    if (y[0] < x[0]) return y;
    return {x[0], x[1] + y[1]};
  }
  void build(vector<int>& a, int u, int l, int r) {
    if (l == r) return void(t[u] = {a[l], 1});  // change here
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
    if (l == r) return void(t[u] = {val, 1});  // change here
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
  SegmentTree<array<int, 2>> st(a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, val;
      cin >> p >> val;
      st.update(p, val);
    } else {
      int l, r;
      cin >> l >> r;
      auto ans = st.query(l, r - 1);
      cout << ans[0] << " " << ans[1] << '\n';
    }
  }
  return 0;
}
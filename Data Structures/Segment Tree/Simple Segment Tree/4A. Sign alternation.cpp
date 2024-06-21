// 21.06.2024 03:40:17
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>  // return type
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T x, T y) {  // change here
    return x + y;
  }
  void build(vector<int>& a, int u, int l, int r) {
    if (l == r) return void(t[u] = a[l]);  // change here
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
    if (l == r) return void(t[u] = val);  // change here
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i & 1) a[i] = -a[i];
  }
  SegmentTree<i64> st(a);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int p, v;
      cin >> p >> v;
      --p;
      if (p & 1) v = -v;
      st.update(p, v);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      auto ans = st.query(l, r);
      if (l & 1) ans = -ans;
      cout << ans << '\n';
    }
  }
  return 0;
}
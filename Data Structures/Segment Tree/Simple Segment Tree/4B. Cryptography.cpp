// 21.06.2024 04:58:34
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>  // return type
class SegmentTree {
  int n, mod;
  vector<T> t;  // tree
 public:
  int add(int a, int b) { return (1LL * a + b) % mod; }
  int mul(int a, int b) { return (1LL * a * b) % mod; }
  T combine(T a, T b) {  // change here
    T res;
    res[0] = add(mul(a[0], b[0]), mul(a[1], b[2]));
    res[1] = add(mul(a[0], b[1]), mul(a[1], b[3]));
    res[2] = add(mul(a[2], b[0]), mul(a[3], b[2]));
    res[3] = add(mul(a[2], b[1]), mul(a[3], b[3]));
    return res;
  }
  void build(vector<T>& a, int u, int l, int r) {
    if (l == r) return void(t[u] = a[l]);  // change here
    int m = l + (r - l) / 2;
    build(a, u << 1, l, m);
    build(a, u << 1 | 1, m + 1, r);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  SegmentTree(vector<T> a, int r) : n((int)a.size()), mod(r) {
    t.resize(4 * n);
    build(a, 1, 0, n - 1);
  }

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
  int r, n, m;
  cin >> r >> n >> m;
  vector<array<int, 4>> a(n);
  for (auto& [a, b, c, d] : a) {
    cin >> a >> b >> c >> d;
  }
  SegmentTree<array<int, 4>> st(a, r);
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    auto ans = st.query(l, r);
    cout << ans[0] << " " << ans[1] << '\n';
    cout << ans[2] << " " << ans[3] << '\n';
    cout << '\n';
  }
  return 0;
}
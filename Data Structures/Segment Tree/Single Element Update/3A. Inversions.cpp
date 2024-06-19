// 20.06.2024 01:34:28
// Count inversions for each index
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
  SegmentTree(int _n) : n(_n) { t.resize(4 * n); }

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

  vector<int> inversions(vector<int>& a) {
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      if (a[i] == n - 1) ans[i] = 0;
      else ans[i] = query(a[i] + 1, n - 1);
      update(a[i], 1);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
    --i; // make the permutation 0 based
  }
  SegmentTree<i64> st(n);
  auto ans = st.inversions(a);
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
  return 0;
}
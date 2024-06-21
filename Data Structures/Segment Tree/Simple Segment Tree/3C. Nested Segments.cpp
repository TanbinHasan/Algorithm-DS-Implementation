// 20.06.2024 20:13:07
// number of segments nested inside the segment i
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

  vector<int> nested_segments(vector<int>& a) {
    vector<int> left(n / 2, -1), ans(n / 2);
    for (int i = 0; i < n; ++i) {
      if (left[a[i]] == -1) {
        left[a[i]] = i;
        continue;
      }
      ans[a[i]] = query(left[a[i]], i);
      update(left[a[i]], 1);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (auto& i : a) {
    cin >> i;
    --i; // make elements 0 based
  }
  SegmentTree<int> st(2 * n);
  auto ans = st.nested_segments(a);
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
  return 0;
}
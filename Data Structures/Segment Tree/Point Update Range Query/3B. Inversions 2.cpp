// 20.06.2024 04:11:48
// reverse version of the previous problem
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
  SegmentTree(int _n) : n(_n) {
    t.resize(4 * n);
    vector<int> a(n, 1);
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
  T find(int k, int u, int l, int r) {
    if (l == r) return l;
    int m = l + (r - l) / 2LL;
    T sl = t[u << 1]; // left subtree sum
    if (sl >= k + 1) return find(k, u << 1, l, m);
    return find(k - sl, u << 1 | 1, m + 1, r);
  }
  T find(int k) { return find(k, 1, 0, n - 1); }

  vector<int> restore_permutation(vector<int>& a) {
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
      int ind = find(a[i]);
      update(ind, 0);
      ans[i] = n - 1 - ind;
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
  }
  SegmentTree<i64> st(n);
  auto ans = st.restore_permutation(a);
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i == n - 1];
  return 0;
}
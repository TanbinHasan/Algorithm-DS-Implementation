/**
 *    author:  T.H666
 *    created: 23.06.2022 07:37:23
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

class SparseTable {
  vector<vector<int>> v;
 public:
  SparseTable(vector<int>& a) {
    int n = (int)a.size();
    int pw = __lg(n);
    v.resize(n, vector<int>(pw + 1));
    for (int i = 0; i < n; ++i) v[i][0] = a[i];
    for (int p = 1; p <= pw; ++p) {
      int x = (1LL << (p - 1));
      for (int i = 0; i + x < n; ++i) {
        v[i][p] = min(v[i][p - 1], v[i + x][p - 1]);
      }
    }
  }
  int query(int l, int r) {
    int x = __lg(r - l + 1);
    return min(v[l][x], v[r - (1LL << x) + 1][x]);
  }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  SparseTable st(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l - 1, r - 1) << '\n';
  }
  return 0;
}
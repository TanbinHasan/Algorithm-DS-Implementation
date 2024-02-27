/**
 *    author:  T.H666
 *    created: 23.06.2022 07:37:23
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

class SparseTable {
 public:
  vector<vector<int>> mat;
  SparseTable(vector<int> &ar) {
    int n = (int)ar.size();
    int pw = __lg(n);
    mat = vector<vector<int>>(n, vector<int>(pw + 1));
    for (int i = 0; i < n; ++i) mat[i][0] = ar[i];
    for (int p = 1; p <= pw; ++p) {
      int x = (1LL << (p - 1));
      for (int i = 0; i + x < n; ++i) {
        mat[i][p] = min(mat[i][p - 1], mat[i + x][p - 1]);
      }
    }
  }
  int query(int l, int r) {
    int x = __lg(r - l + 1);
    return min(mat[l][x], mat[r - (1LL << x) + 1][x]);
  }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  SparseTable st(ar);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l - 1, r - 1) << '\n';
  }
  return 0;
}
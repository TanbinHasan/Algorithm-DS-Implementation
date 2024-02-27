/**
 *    author:  T.H666
 *    created: 27.01.2022 18:05:21
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

using vvi = vector<vector<int>>;
vvi PrefixSum2D(vvi &mat, int n, int m) {
  vvi pref(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
  return pref;
}

/*
Naive Approach
vvi PrefixSum2D(vvi &mat, int n, int m) {
  vvi pref = mat;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      pref[i][j] += pref[i][j - 1];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      pref[j][i] += pref[j - 1][i];
    }
  }
  return pref;
} 
*/

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi mat(n, vector<int>(m));
  for (auto &i : mat) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  auto pref = PrefixSum2D(mat, n, m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << pref[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
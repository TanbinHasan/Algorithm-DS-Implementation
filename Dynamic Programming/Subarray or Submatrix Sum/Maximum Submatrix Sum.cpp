/**
 *    author:  T.H666
 *    created: 07.02.2022 20:02:13
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

int MaxSubMatSum(vector<vector<int>> &mat, int r, int c) {
  vector<vector<int>> pref(r, vector<int>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (!j) pref[i][j] = mat[i][j];
      else pref[i][j] = pref[i][j - 1] + mat[i][j];
    }
  }
  int mxsum = LLONG_MIN;
  for (int i = 0; i < c; ++i) {
    for (int j = i; j < c; ++j) {
      vector<int> ar;
      for (int k = 0; k < r; ++k) {
        int x = ((i == 0) ? (pref[k][j]) : (pref[k][j] - pref[k][i - 1]));
        ar.push_back(x);
      }
      int mx = LLONG_MIN, sum = 0;
      for (auto &k : ar) {
        sum += k;
        mx = max(mx, sum);
        sum = max(0LL, sum);
      }
      mxsum = max(mxsum, mx);
    }
  }
  return mxsum;
}

/* 
Process:
  1. determine prefix sum of all rows 
  2. select 1st & last column
  3. traversing all rows 
  4. use kadane algorithm to determine maximum
*/

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  for (auto &i : mat) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  cout << MaxSubMatSum(mat, n, m);
  return 0;
}
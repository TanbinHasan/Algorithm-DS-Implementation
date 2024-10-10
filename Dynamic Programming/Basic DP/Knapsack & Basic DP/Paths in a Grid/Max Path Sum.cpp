/**
 *    author:  Tanbin_Hasan
 *    created: 16.06.2021 02:06:04
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

/*
pseudocode:
int f(int i, int j) {
  if (i == n || j == m) return 0;
  if (~dp[i][j]) return dp[i][j];
  dp[i][j] = f(i + 1, j);
  dp[i][j] = max(dp[i][j], f(i, j + 1)) + g[i][j];
  return dp[i][j];
}  
*/

i64 MaxPathSum(vector<vector<int>> &g, int n, int m) {
  vector<vector<i64>> dp(n + 1, vector<i64>(m + 1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + g[i][j];
    }
  }
  return dp[0][0];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (auto &i : g) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  cout << MaxPathSum(g, n, m) << '\n';
  return 0;
}
/*
https://atcoder.jp/contests/dp/submissions/58113508  
*/
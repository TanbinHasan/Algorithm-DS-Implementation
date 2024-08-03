/**
 *    author:  Tanbin_Hasan
 *    created: 19.06.2021 14:56:25
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector<vector<i64>> dp;

i64 DP(vector<pair<int, int>>& a, int n, int W) {
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= W; ++j) {
      auto [w, p] = a[i];
      dp[i][j] = dp[i + 1][j]; // option1
      if (j - w >= 0) dp[i][j] = max(dp[i][j], dp[i + 1][j - w] + p); // option2
    }
  }
  return dp[0][W];
}

void DP_Path(vector<pair<int, int>>& a, int i, int n, int j) {
  if (i == n || !j) return;
  auto [w, p] = a[i];
  if (j >= w && dp[i + 1][j - w] + p >= dp[i + 1][j]) {
    cout << i << " ";
    DP_Path(a, i + 1, n, j - w);
  } else DP_Path(a, i + 1, n, j);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, W;
  cin >> n >> W;
  vector<pair<int, int>> a(n);
  for (auto& [w, p] : a) {
    cin >> w >> p;
  }
  dp.resize(n + 1, vector<i64>(W + 1));
  cout << DP(a, n, W) << '\n';
  // DP_Path(a, 0, n, W);
  return 0;
}
/* 
https://atcoder.jp/contests/dp/submissions/55615648
https://atcoder.jp/contests/dp/submissions/55617454
*/
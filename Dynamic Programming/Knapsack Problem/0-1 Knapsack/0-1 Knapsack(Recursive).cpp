/**
 *    author:  Tanbin_Hasan
 *    created: 19.06.2021 04:44:15
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector<vector<i64>> dp;

i64 DP(vector<pair<int, int>>& a, int i, int n, int j) {
  if (j < 0) return (i64)-1e18;
  if (i == n || !j) return 0;
  i64& ret = dp[i][j];
  if (~ret) return ret;
  i64 o1 = DP(a, i + 1, n, j - a[i].first) + a[i].second;
  i64 o2 = DP(a, i + 1, n, j);
  return ret = max(o1, o2);
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
  dp.assign(n + 1, vector<i64>(W + 1, -1));
  cout << DP(a, 0, n, W) << '\n';
  // DP_Path(a, 0, n, W);
  return 0;
}
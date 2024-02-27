/**
 *    author:  Tanbin_Hasan
 *    created: 19.06.2021 14:56:25
**/
#include <bits/stdc++.h>

using namespace std;

int MxValue(vector<pair<int,int>> &item, int n, int sum) {
  vector<int> val(sum + 1);
  for (int pos = 0; pos < n; ++pos) {
    auto &[a, b] = item[pos];
    for (int x = sum; x > 0; --x) {
      if (x - a < 0) continue;
      val[x] = max(val[x], val[x - a] + b);
    }
  }
  return val[sum];
}

#ifdef pathalso
int f(vector<pair<int, int>>& vp, int sz, int m) {
  vector<vector<int>> dp(sz + 1, vector<int>(m + 1));
  for (int n = 1; n <= sz; ++n) {
    for (int w = 1; w <= m; ++w) {
      auto [x, y] = vp[n]; // x is weight, y is profit
      if (x <= w) dp[n][w] = max(dp[n - 1][w - x] + y, dp[n - 1][w]);
      else dp[n][w] = dp[n - 1][w];
    }
  }
  for (int i = 0; i <= sz; ++i) {
    for (int j = 0; j <= m; ++j) {
      cout << dp[i][j] << " ";
    }
    cout << '\n';
  }
  vector<int> mark(sz + 1);
  int i = sz, k = m;
  while (i > 0 && k > 0) {
    if (dp[i][k] != dp[i - 1][k]) {
      mark[i] = 1;
      k -= vp[i].first;
    }
    --i;
  }
  for (int i = 1; i <= sz; ++i) {
    cout << mark[i] << " ";
  }
  cout << '\n';
  return dp[sz][m];
}
#endif

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, lim;
  cin >> n >> lim;
  vector<pair<int,int>> item(n);
  for (int i = 0; i < n; ++i) {
    cin >> item[i].first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> item[i].second;
  }
  cout << MxValue(item, n, lim);
  return 0;
}
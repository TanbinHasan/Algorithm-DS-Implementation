/**
 *    author:  BlackIce666
 *    created: 30.10.2023 18:46:58
**/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

int LPS(string& s) {
  int n = (int)s.size();
  string r = s;
  reverse(r.begin(), r.end());
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      if (s[x - 1] == r[y - 1]) dp[x][y] = dp[x - 1][y - 1] + 1;
      else dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
    }
  }
  return dp[n][n];
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  cout << LPS(s) << '\n';
  
  return 0;
}
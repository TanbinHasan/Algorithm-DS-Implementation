/**
 *    author:  Tanbin_Hasan
 *    created: 23.09.2021 00:45:06
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = (int)s.size(), m = (int)t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
        continue;
      }
      dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  
  string lcs;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (s[i] == t[j]) {
      lcs.push_back(s[i]);
      ++i, ++j;
      continue;
    }
    ((dp[i + 1][j] >= dp[i][j + 1]) ? (++i) : (++j));
  }
  cout << lcs << '\n';
  return 0;
}
/*
https://atcoder.jp/contests/dp/submissions/58113373 
*/
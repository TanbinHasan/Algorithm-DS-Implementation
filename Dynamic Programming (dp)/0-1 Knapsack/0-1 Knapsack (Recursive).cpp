/**
 *    author:  Tanbin_Hasan
 *    created: 19.06.2021 04:44:15
**/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> item;
vector<vector<int>> val(2001, vector<int>(2001, -1));

int MaxValue(int n, int pos, int x) {
  if (x < 0) return INT_MIN;
  if (!x || pos == n) return 0;
  if (val[pos][x] != -1) return val[pos][x];
  int opt1 = MaxValue(n, pos + 1, x - item[pos].first) + item[pos].second;
  int opt2 = MaxValue(n, pos + 1, x);
  return val[pos][x] = max(opt1, opt2);
}

#ifdef Iterative
int f(vector<pair<int, int>>& vp, int sz, int m) {
  vector<vector<int>> dp(sz + 1, vector<int>(m + 1));
  for (int n = 1; n < sz; ++n) {
    for (int w = 1; w <= m; ++w) {
      int opt1 = dp[n - 1][w];
      int opt2 = opt1;
      if (w - vp[n].first < 0) continue;
      opt2 = dp[n - 1][w - vp[n].first] + vp[n].second;
      dp[n][w] = max(opt1, opt2);
    }
  }
  return dp[sz][m];
}
#endif

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, n;
  cin >> x >> n;
  item.assign(n, {});
  for (auto &[x, y] : item) {
    cin >> x >> y;
  }
  cout << MaxValue(n, 0, x);
  return 0;
}

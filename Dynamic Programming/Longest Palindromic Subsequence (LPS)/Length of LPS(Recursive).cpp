/**
 *    author:  BlackIce666
 *    created: 30.10.2023 18:46:58
**/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

const int lim = 1001; // n + 1;
vector<vector<int>> dp(lim, vector<int>(lim, -1));
// s is the string and r is the reverse string of s
int LPS(string& s, string& r, int x, int y) {
  if (x == 0 || y == 0) return 0;
  int& ret = dp[x][y];
  if (ret != -1) return ret;
  ret = 0;
  if (s[x - 1] == r[y - 1]) ret = LPS(s, r, x - 1, y - 1) + 1;
  else ret = max(LPS(s, r, x - 1, y), LPS(s, r, x, y - 1));
  return ret;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  int n = (int)s.size();
  cout << LPS(s, r, n, n) << '\n';
  return 0;
}
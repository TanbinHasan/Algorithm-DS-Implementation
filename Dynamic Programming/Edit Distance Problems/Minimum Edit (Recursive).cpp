/**
 *    author:  Tanbin_Hasan
 *    created: 17.06.2021 01:32:43
 **/
#include <bits/stdc++.h>

using namespace std;

const int MX = 5001;
int dp[MX][MX];
string a, b;

int DP(int i, int j) {
  if (i < 0 && j < 0) return 0;
  else if (i < 0) return j + 1;
  else if (j < 0) return i + 1;
  int& ret = dp[i][j];
  if (~ret) return ret;

  int o1 = DP(i, j - 1) + 1;                   // add new character at the end of a
  int o2 = DP(i - 1, j) + 1;                   // remove the last character from a
  int o3 = DP(i - 1, j - 1) + (a[i] != b[j]);  // modify the character or not
  return ret = min({o1, o2, o3});
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  cout << DP((int)a.size() - 1, (int)b.size() - 1);
  return 0;
}
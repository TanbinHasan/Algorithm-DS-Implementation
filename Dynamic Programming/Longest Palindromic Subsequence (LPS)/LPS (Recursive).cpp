/**
 *    author:  BlackIce666
 *    created: 30.10.2023 18:46:58
**/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1001;
int dp[MX][MX];
string s, r;
int n;

int DP(int i, int j) {
  if (i == n || j == n) return 0;
  int& ret = dp[i][j];
  if (~ret) return ret;
  if (s[i] == r[j]) ret = DP(i + 1, j + 1);
  else ret = max(DP(i + 1, j), DP(i, j + 1));
  return ret;
}

string path;
void DP_Path(int i, int j) {
  if (i == n || j == n) return;
  if (s[i] == r[j]) {
    path.push_back(s[i]);
    DP_Path(i + 1, j + 1);
  } else if (DP(i + 1, j) >= DP(i, j + 1)) DP_Path(i + 1, j);
  else DP_Path(i, j + 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  n = (int)s.size();
  memset(dp, -1, sizeof dp);
  cout << DP(0, 0) << '\n';
  return 0;
}
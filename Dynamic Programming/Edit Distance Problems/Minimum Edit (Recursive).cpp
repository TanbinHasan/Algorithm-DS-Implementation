/**
 *    author:  Tanbin_Hasan
 *    created: 17.06.2021 01:32:43
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp(5001, vector<int>(5001, -1));

int f(string &a, string &b, int i, int j) {
  if (i < 0 && j < 0) return 0;
  else if (i < 0) return j + 1;
  else if (j < 0) return i + 1;
  if (dp[i][j] != -1) return dp[i][j];
  int o1 = f(a, b, i, j - 1) + 1;                  // add new character at the end of a
  int o2 = f(a, b, i - 1, j) + 1;                  // remove the last character from a
  int o3 = f(a, b, i - 1, j - 1) + (a[i] != b[j]); // modify the character or not
  return dp[i][j] = min({o1, o2, o3});
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n = (int)a.size() - 1;
  int m = (int)b.size() - 1;
  cout << f(a, b, n, m);
  return 0;
}
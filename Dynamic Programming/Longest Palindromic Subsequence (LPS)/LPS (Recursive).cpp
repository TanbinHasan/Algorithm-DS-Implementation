/**
 *    author:  BlackIce666
 *    created: 30.10.2023 18:46:58
**/
#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
const int MX = 1001;

int dp[MX][MX];
string s;
int n;

int lps(int l, int r) {
  if (l > r || l == n || r == -1) return 0;
  int& ret = dp[l][r];
  if (~ret) return ret;
  if (s[l] == s[r]) ret = lps(l + 1, r - 1) + (l == r ? 1 : 2);
  else ret = max(lps(l + 1, r), lps(l, r - 1));
  return ret;
}

// string path;
// void walk(int i, int j) {
//   if (i == n || j == n) return;
//   if (s[i] == r[j]) {
//     path.push_back(s[i]);
//     walk(i + 1, j + 1);
//   } else if (rec(i + 1, j) >= rec(i, j + 1)) walk(i + 1, j);
//   else walk(i, j + 1);
// }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  n = (int)s.size();
  memset(dp, -1, sizeof dp);
  cout << lps(0, n - 1) << '\n';
  return 0;
}
// https://toph.co/p/convert-string-into-palindrome
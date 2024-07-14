/**
 *    author:  Tanbin_Hasan
 *    created: 14.06.2021 20:52:51
 **/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> len(1001, vector<int>(1001, -1));

int LengthofLCS(string &a, string &b, int x, int y) {
  if (x == (int)a.size() || y == (int)b.size()) return 0;
  if (len[x][y] != -1) return len[x][y];
  int ans = 0;
  if (a[x] == b[y]) ans = 1 + LengthofLCS(a, b, x + 1, y + 1);
  else ans = max(LengthofLCS(a, b, x + 1, y), LengthofLCS(a, b, x, y + 1));
  return len[x][y] = ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  cout << LengthofLCS(a, b, 0, 0);
  return 0;
}
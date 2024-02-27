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
  if (a[x] == b[y]) {
    ans = 1 + LengthofLCS(a, b, x + 1, y + 1);
  } else {
    ans = max(LengthofLCS(a, b, x + 1, y), LengthofLCS(a, b, x, y + 1));
  }
  return len[x][y] = ans;
}

void Path(string &a, string &b, int x, int y, string &ans) {
  if (x == (int)a.size() || y == (int)b.size()) return;
  if (a[x] == b[y]) {
    Path(a, b, x + 1, y + 1, ans);
    ans.push_back(a[x]);
  } else if (len[x + 1][y] >= len[x][y + 1]) {
    Path(a, b, x + 1, y, ans);
  } else {
    Path(a, b, x, y + 1, ans);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  cout << LengthofLCS(a, b, 0, 0) << '\n';
  string ans;
  Path(a, b, 0, 0, ans);
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}
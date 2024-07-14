/**
 *    author:  Tanbin_Hasan
 *    created: 15.06.2021 19:53:50
 **/
#include <bits/stdc++.h>

using namespace std;

int LengthofLCS(string &a, string &b) {
  vector<vector<int>> len((int)a.size() + 5, vector<int>((int)b.size() + 5));
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    for (int j = (int)b.size() - 1; j >= 0; --j) {
      if (a[i] == b[j]) {
        len[i][j] = len[i + 1][j + 1] + 1;
      } else {
        len[i][j] = max(len[i + 1][j], len[i][j + 1]);
      }
    }
  }
  return len[0][0];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  cout << LengthofLCS(a, b);
  return 0;
}
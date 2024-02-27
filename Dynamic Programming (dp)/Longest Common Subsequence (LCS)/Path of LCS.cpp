/**
 *    author:  Tanbin_Hasan
 *    created: 23.09.2021 00:45:06
 **/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> len(1001, vector<int>(1001));

string PathofLIS(string &a, string &b) {
  int lenA = (int)a.size(), lenB = (int)b.size();
  for (int i = lenA - 1; i >= 0; --i) {
    for (int j = lenB - 1; j >= 0; --j) {
      if (a[i] == b[j]) len[i][j] = len[i + 1][j + 1] + 1;
      else len[i][j] = max(len[i + 1][j], len[i][j + 1]);
    }
  }
  string s;
  int i = 0, j = 0;
  while (i < lenA && j < lenB) {
    if (a[i] == b[j]) {
      s.push_back(a[i]);
      ++i, ++j;
      continue;
    }
    (len[i + 1][j] > len[i][j + 1]) ? ++i : ++j;
  }
  return s;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  string lcs = PathofLIS(a, b);
  cout << lcs << '\n';
  return 0;
}
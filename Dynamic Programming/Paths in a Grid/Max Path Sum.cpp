/**
 *    author:  Tanbin_Hasan
 *    created: 16.06.2021 02:06:04
**/
#include <bits/stdc++.h>

using namespace std;

int64_t MaxPathSum(vector<vector<int>> &ar, int n, int m) {
  vector<vector<int64_t>> val(n + 1, vector<int64_t>(m + 1));
  for (int i = n - 1; i >= 0; --i)
    for (int j = m - 1; j >= 0; --j)
      val[i][j] = max(val[i + 1][j], val[i][j + 1]) + ar[i][j];
  return val[0][0];
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ar(n, vector<int>(m));
  for (auto &i : ar) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  cout << MaxPathSum(ar, n, m);
  return 0;
}
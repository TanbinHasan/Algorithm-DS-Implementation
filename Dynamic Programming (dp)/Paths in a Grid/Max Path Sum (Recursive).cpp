/**
 *    author:  Tanbin_Hasan
 *    created: 16.06.2021 02:06:04
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ar(1001, vector<int>(1001)), val(1001, vector<int>(1001));
vector<bitset<1001>> mark(1001);
int MaxPathSum(int n, int m, int i, int j) {
  if (i == n || j == m) return 0;
  if (mark[i][j]) return val[i][j];
  mark[i][j] = 1;
  return val[i][j] = max(MaxPathSum(n, m, i + 1, j), MaxPathSum(n, m, i, j + 1)) + ar[i][j];
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ar[i][j];
    }
  }
  cout << MaxPathSum(n, m, 0, 0);
  return 0;
}
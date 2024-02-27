/**
 *    author:  Tanbin_Hasan
 *    created: 25.09.2021 00:33:21
**/
#include <bits/stdc++.h>

using namespace std;

int TotalWay(vector<int> &ar, int n, int tar) {
  vector<vector<int>> val(n + 1, vector<int>(tar + 1));
  val[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= tar; ++j) {
      val[i][j] = val[i - 1][j];
      if (j - ar[i - 1] < 0) continue;
      val[i][j] = (val[i][j] + val[i][j - ar[i - 1]]) % 1000000007;
    }
  }
  return val[n][tar];
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << TotalWay(ar, n, target);
  return 0;
}
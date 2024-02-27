/**
 *    author:  Tanbin_Hasan
 *    created: 25.09.2021 00:22:24
 **/
#include <bits/stdc++.h>

using namespace std;

int TotalWay(vector<int> &ar, int n, int tar) {
  vector<int> dp(tar + 1);
  dp[0] = 1;
  for (auto& i : ar) {
    for (int j = tar; j >= i; --j) {
      dp[j] = (dp[j] + dp[j - i]) % 1000000007;
    }
  }
  return dp[tar];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << TotalWay(ar, n, target);
  return 0;
}
/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 01:07:04
**/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1001;
int dp[MX][MX];
vector<int> a;
int n;

int lis_len(int i, int prv) {
  if (i == n) return 0;
  int& ret = dp[i][prv];
  if (~ret) return ret;
  ret = lis_len(i + 1, prv); // exclude current element
  if (prv == n || a[i] > a[prv]) ret = max(ret, lis_len(i + 1, i) + 1); // include current element
  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (auto& i : a) {
    cin >> i;
  }
  memset(dp, -1, sizeof dp);
  cout << lis_len(0, n) << '\n';
  return 0;
}
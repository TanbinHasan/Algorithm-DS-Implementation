/**
 *    author:  Tanbin_Hasan
 *    created: 16.06.2021 20:01:32
**/
// using elements once
#include <bits/stdc++.h>
using namespace std;
 
typedef long long i64;
 
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
 
  i64 k = accumulate(a.begin(), a.end(), 0LL);
  vector<int> dp(k + 1);
  dp[0] = 1;
  for (auto& i : a) {
    for (int j = k; j >= i; --j) { // for multiple use of a[], just reverse the loop
      if (dp[j - i]) dp[j] = 1;
    }
  }
  cout << accumulate(dp.begin(), dp.end(), 0LL) - 1 << '\n';
  for (int i = 1; i <= k; ++i) {
    if (dp[i]) cout << i << " ";
  }
  cout << '\n';
  return 0;
}
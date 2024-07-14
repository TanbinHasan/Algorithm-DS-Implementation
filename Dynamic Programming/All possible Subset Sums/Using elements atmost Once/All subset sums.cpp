/**
 *    author:  Tanbin_Hasan
 *    created: 16.06.2021 20:01:32
**/
#include <bits/stdc++.h>
 
using namespace std;

bitset<100001> dp(1); // Safe: 1e6

void AllSum(vector<int> &ar, int sum) {
  for (auto &i : ar) {
    for (int j = sum; j >= i; --j) {
      if (dp[j - i]) dp[j] = 1;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  int sum = accumulate(ar.begin(), ar.end(), 0LL);
  AllSum(ar, sum);
  cout << dp.count() << '\n'; // Size of all possible sums
  for (int i = 0; i <= sum; ++i) {
    if (dp[i]) cout << i << ' ';
  }
  return 0;
}
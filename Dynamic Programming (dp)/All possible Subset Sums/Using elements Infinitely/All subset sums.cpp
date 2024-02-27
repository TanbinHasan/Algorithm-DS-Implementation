/**
 *    author:  Tanbin_Hasan
 *    created: 22.09.2021 22:04:44
**/
#include <bits/stdc++.h>

using namespace std;

bitset<100001> dp(1); 

void AllSum(vector<int> &ar, int sum) {
  for (auto &i : ar) {
    for (int j = i; j <= sum; ++j) {
      if (dp[j - i]) dp[j] = 1;
    }
  }
}

#ifdef Alternative
void AllSum(vector<int> &ar, int sum) {
  for (int s = 1; s <= sum; ++s) {
    for (auto &i : ar) {
      if (s - i < 0) continue;
      if (dp[s - i]) dp[s] = 1;
    }
  }
}
#endif

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
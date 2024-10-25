#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }

  vector<int> freq(n + 1);
  for (auto& i : a) ++freq[i];
  vector<bool> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i <= n; ++i) {
    if (!freq[i]) continue;
    auto new_dp = dp;
    for (int j = 0; j < i; ++j) {
      int sum = 0;
      for (int k = j, cnt = 0; k <= n; k += i, ++cnt) {
        if (cnt > freq[i]) sum -= dp[k - i * cnt--];
        if (sum > 0) new_dp[k] = true;
        sum += dp[k];
      }
    }
    swap(dp, new_dp);
  }
  for (int i = 0; i <= n; ++i) {
    if (dp[i]) cout << i << " ";
  }
  return 0;
}
/* 
Constraints: Sum of a[i] <= N
then time complexity O(N * sqrt(N))
*/
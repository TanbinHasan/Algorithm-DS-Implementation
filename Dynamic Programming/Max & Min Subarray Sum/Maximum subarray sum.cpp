/**
 *    author: Tanbin_Hasan
 *    created: 12.05.2021 01:44:20
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

int MaxSubArSum(vector<int> &ar) {
  int ans = ar.front(), sum = 0;
  for (auto &i : ar) {
    sum += i;
    ans = max(ans, sum);
    sum = max(sum, 0LL);
  }
  return ans;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << MaxSubArSum(ar) << '\n';
  return 0;
}

#ifdef Normal
long long MaxSubArSum(vector<long long> &ar) {
  long long ans = ar.front(), sum = 0, min_sum = 0;
  for (auto &i : ar) {
    sum += i;
    ans = max(ans, sum - min_sum);
    min_sum = min(min_sum, sum);
  }
  return ans;
}
#endif
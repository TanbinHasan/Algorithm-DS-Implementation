/**
 *    author: Tanbin_Hasan
 *    created: 12.05.2021 01:44:20
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

// for Minimum, use min function & invert all >, < operators
// if you need start & end point along with sum
tuple<i64, int, int> max_sub_sum(vector<int>& a, int n) {
  tuple<i64, int, int> ans = {0, 0, 0};
  auto& [v, l, r] = ans;
  i64 sum = 0;
  int start = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (sum > v) {
      v = sum;
      l = start;
      r = i;
    }
    if (sum < 0) sum = 0, start = i + 1;
  }
  return ans;
}

i64 max_sub_sum(vector<int>& a) {
  i64 ans = 0, sum = 0;
  for (auto &i : a) {
    sum += i;
    ans = max(ans, sum);
    sum = max(sum, 0LL);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  cout << max_sub_sum(a) << '\n';
  return 0;
}

#ifdef Normal
i64 max_sub_sum(vector<i64>& a) {
  i64 ans = 0, sum = 0, mn = 0;
  for (auto &i : a) {
    sum += i;
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
  }
  return ans;
}
#endif
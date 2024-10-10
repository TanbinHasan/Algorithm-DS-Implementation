// Using each coin infinite number of times
#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int DP(vector<int>& c, int x) {
  if (!x) return 0;
  if (~dp[x]) return dp[x];
  dp[x] = (int)2e9;
  for (auto& i : c) {
    if (x - i >= 0) dp[x] = min(dp[x], DP(c, x - i) + 1);
  }
  return dp[x];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (auto& i : c) {
    cin >> i;
  }
  dp.assign(x + 1, -1);
  int ans = DP(c, x);
  cout << ((ans == (int)2e9) ? (-1) : (ans)) << '\n';
  return 0;
}
/*
Number of ways:
1. No Order: https://cses.fi/problemset/result/10544952/
2. Ordered: https://cses.fi/problemset/result/10545041/  
*/
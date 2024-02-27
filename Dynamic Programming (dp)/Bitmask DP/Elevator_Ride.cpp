#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

void PreCalc(void) {}

/*
There are n people who want to get to the top of a building which has only one elevator. 
You know the weight of each person and the maximum allowed weight in the elevator. 
What is the minimum number of elevator rides?  
*/

int MinRide(vector<int>& a, int n, int lim) {
  vector<pair<int, int>> dp((1LL << n)); // ride, minimum weight
  dp[0] = {1, 0};
  for (int mask = 1; mask < (1LL << n); ++mask) {
    dp[mask] = {n, 0}; // intially n rides are needed
    for (int i = 0; i < n; ++i) {
      if (!(mask & (1LL << i))) continue;
      auto [cr, cw] = dp[mask ^ (1LL << i)];
      if (cw + a[i] <= lim) cw += a[i];
      else {
        ++cr;
        cw = a[i];
      }
      dp[mask] = min(dp[mask], make_pair(cr, cw));
    }
  }
  return dp[(1LL << n) - 1].first;
}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, lim;
  cin >> n >> lim;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  cout << MinRide(a, n, lim) << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
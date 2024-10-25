#include <bits/stdc++.h>
using namespace std;

const int MX = (int)1e5 + 1; // sum of array + 1
bitset<MX> dp;

void CalcSubsets(vector<int> a) {
  dp.reset();
  dp[0] = 1;
  for (auto& i : a) dp |= (dp << i);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  CalcSubsets(a);
  while (q--) {
    int x;
    cin >> x;
    if (x >= MX) cout << 0 << '\n';
    else cout << dp[x] << "\n";
  }
  return 0;
}
/*
Complexity: O(n * MAX(a[i]))
https://www.geeksforgeeks.org/subset-sum-queries-using-bitset/
https://www.spoj.com/problems/ADACOINS/
*/
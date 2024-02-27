/**
 *    author:  T.H666
 *    created: 29.10.2023 19:25:29
**/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

int SSOD(int n) {
  int res = 0;
  for (int i = 1; i * i <= n; ++i) {
    int p = n / i;
    int x = i * (p - i + 1);
    int y = (p * (p + 1)) / 2LL - (i * (i + 1)) / 2LL;
    res += (x + y);
  }
  return res;
}

using namespace std;

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cout << SSOD(n) << '\n';
  }
  return 0;
}
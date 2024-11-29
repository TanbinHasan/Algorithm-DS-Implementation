/**
 *    author:  T.H666
 *    created: 29.10.2023 19:25:29
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 SSOD(i64 n) {
  int res = 0;
  for (i64 i = 1; i * i <= n; ++i) {
    i64 p = n / i;
    i64 x = i * (p - i + 1);
    i64 y = (p * (p + 1)) / 2LL - (i * (i + 1)) / 2LL;
    res += (x + y);
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    i64 n;
    cin >> n;
    cout << SSOD(n) << '\n';
  }
  return 0;
}
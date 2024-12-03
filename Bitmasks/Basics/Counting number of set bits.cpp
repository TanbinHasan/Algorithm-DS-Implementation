/**
 *    Author  : Tanbin_Hasan
 *    Created : 17.09.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int popcount(i64 n) {
  int cnt = 0;
  while (n > 0) {
    ++cnt;
    n &= (n - 1);
  }
  return cnt;
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << popcount(n) << '\n';
  cout << __builtin_popcountll(n) << '\n'; // By Builtin Function
  return 0;
}

#ifdef DRAFT
Above approach is faster than following approach,
while (n > 0) {
  if (1LL & n) ++cnt;
    n >>= 1;
}
#endif // DRAFT

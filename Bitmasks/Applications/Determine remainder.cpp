/**
 *    Author  : Ador
 *    Created : 16.08.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void) {
  int n, d, rem;
  cin >> n >> d;
  rem = n & (d - 1);
  cout << rem << "\n";
  return 0;
}

#ifdef DRAFT
    N.B : d have to be 2^x
    n = 102 = 1100110
    d = 8 = 1000

              n = 1100110
        (d - 1) = 0000111
    n & (d - 1) = 0000110 = 6
#endif

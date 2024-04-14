/**
 *    Author  : Ador
 *    Created : 26.08.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void) {
  int n;
  cin >> n;
  if (!(n & (n - 1)))
    cout << n << " is a power of 2\n";
  else
    cout << n << " isn't a power of two\n";
  return 0;
}

#ifdef DRAFT
Condtion : (n &(n - 1)) have to be zero.
#endif
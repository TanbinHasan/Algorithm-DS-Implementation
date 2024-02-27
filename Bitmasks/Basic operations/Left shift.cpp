/**
 *    Author  : Ador
 *    Created : 13.08.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void) {
  int n , d; 
  cin >> n >> d;
  cout << (n << d) << "\n";
  return 0;
}

#ifdef DRAFT
   N.B : d have to be 2^x
   a << 1 = a * pow(2 , 1) = a * 2
   a << 2 = a * pow(2 , 2) = a * 4
   a << 3 = a * pow(2 , 3) = a * 8
#endif

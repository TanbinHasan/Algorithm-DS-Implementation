/**
 *    Author  : Ador
 *    Created : 14.08.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void) {
  int a , b; 
  cin >> a >> b;
  cout << (a | b) << "\n"; 
  // You've to use this parenthesis " () ", otherwise verdict will be "Compilation error"
  return 0;
}

#ifdef DRAFT
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1

         17 = 10001 // It's called bitwise OR cause it works bit by bit
         18 = 10010
    17 | 18 = 10011 = 19
#endif

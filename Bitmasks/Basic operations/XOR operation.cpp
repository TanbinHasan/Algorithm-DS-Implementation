/**
 *    Author  : Ador
 *    Created : 13.08.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void) {
  int a , b;
  cin >> a >> b;
  cout << (a ^ b) << " ";
  // You've to use this parenthesis " () ", otherwise verdict will be "Compilation error"
  cout << ((a & ~b) | (~a & b)) << "\n";
  return 0;
}

#ifdef DRAFT
    0^0 = 0
    1^0 = 1
    0^1 = 1
    1^1 = 0

    (a ^ b) = ((a & ~b) | (~a & b))
         17 = 10001 // It's called bitwise XOR cause it works bit by bit
         18 = 10010
    17 ^ 18 = 00011 = 3
    Firstly ,
         a = 10001
        ~b = 01101
    a & ~b = 00001
    Secondly ,
        ~a = 01110
         b = 10010
    ~a & b = 00010
    Finally ,
                 a & ~b = 00001
                 ~a & b = 00010
    (a & ~b) | (~a & b) = 00011 = 3
#endif

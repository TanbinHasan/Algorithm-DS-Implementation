/**
 *    Author  : Ador
 *    Created : 27.08.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

string Decimal_to_Binary(int n) {
  string s;
  for (int i = 0; i < 63; ++i)
    s += bool(n & (1LL << i)) + '0'; // Here , (1LL << i) is also called "AND Mask" 
  reverse(s.begin(), s.end());
  return s;
}

signed main(void) {
  int n;
  cin >> n;
  cout << Decimal_to_Binary(n) << "\n";
  return 0;
}
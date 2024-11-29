/**
 *    Author : Tanbin_Hasan
 *    Created : 15.07.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 gcd(i64 x, i64 y) {
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x;
}

#ifdef Recursive_Version
i64 gcd(i64 x, i64 y) {
  if (!y) return x;
  return gcd(y, x % y);
}
#endif

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 a, b;
  cin >> a >> b;
  cout << "GCD of " << a << " & " << b << " = " << gcd(a, b) << '\n';
  cout << "LCM of " << a << " & " << b << " = " << a / gcd(a, b) * b << '\n';
  return 0;
}
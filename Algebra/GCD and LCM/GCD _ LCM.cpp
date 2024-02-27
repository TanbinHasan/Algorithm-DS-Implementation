/**
 *    Author : Tanbin_Hasan
 *    Created : 15.07.2020
 **/
#include <iostream>

using namespace std;

int64_t gcd(int64_t x, int64_t y) {
  while (y) {
    x %= y;
    swap(x, y);
  }
  return x;
}

#ifdef Recursive_Version
int64_t gcd(int64_t x, int64_t y) {
  if (!y) {
    return x;
  }
  return gcd(y, x % y);
}
#endif

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t a, b;
  cin >> a >> b;
  cout << "GCD of " << a << " & " << b << " = " << gcd(a, b) << '\n';
  cout << "LCM of " << a << " & " << b << " = " << a / gcd(a, b) * b << '\n';
  return 0;
}
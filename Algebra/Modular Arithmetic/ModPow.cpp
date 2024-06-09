/**
 *    Author  : Tanbin_Hasan
 *    Created : 17.01.2021
 **/
#include <bits/stdc++.h>

using namespace std;

// For Mod Inverse: power(n , mod - 2 , mod)
int power(int b, int p, int mod) {
  b %= mod;
  if (b < 0) b += mod;
  int res = 1;
  while (p) {
    if (p & 1) res = (1LL * (res % mod) * (b % mod)) % mod;
    b = (1LL * (b % mod) * (b % mod)) % mod;
    p >>= 1;
  }
  return res;
}

/*
  Recursive approach:
int power(int n, int p, int mod) {
  if (!p) return 1;
  if (p & 1) return ((n % mod) * power(n, p - 1, mod)) % mod;
  int x = power(n, p >> 1, mod);
  return ((x % mod) * (x % mod)) % mod;
}
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  cout << power(n, p, 1000000007) << '\n';
  return 0;
}
/**
 *    Author  : Tanbin_Hasan
 *    Created : 17.01.2021
 **/
#include <bits/stdc++.h>

using namespace std;

// For Mod Inverse: BigMod(n , md - 2 , md)
int BigMod(int b, int p, int md) {
  b %= md;
  if (b < 0) b += md;
  int res = 1;
  while (p) {
    if (p & 1) res = (1LL * (res % md) * (b % md)) % md;
    b = (1LL * (b % md) * (b % md)) % md;
    p >>= 1;
  }
  return res;
}

/*
  Recursive approach:
int BigMod(int n, int p, int md) {
  if (!p) return 1;
  if (p & 1) return ((n % md) * BigMod(n, p - 1, md)) % md;
  int x = BigMod(n, p >> 1, md);
  return ((x % md) * (x % md)) % md;
}
*/

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  cout << BigMod(n, p, 1000000007) << '\n';
  return 0;
}
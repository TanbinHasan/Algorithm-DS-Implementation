/**
 *    Author  : Tanbin_Hasan
 *    Created : 28.10.2023 04:19:35
 **/
#include <bits/stdc++.h>

using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;
u64 BigMod(u64 b, u64 p, u64 md) {
  b %= md;
  u64 res = 1;
  while (p > 0) {
    if (p & 1) res = ((u128) res * b) % md;
    b = ((u128)b * b) % md;
    p >>= 1;
  }
  return res;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = BigMod(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int i = 1; i < s; ++i) {
    x = ((u128) x * x) % n;
    if (x == n - 1) return false;
  }
  return true;
}

bool MillerRobin(u64 n) {
  if (n < 2) return false;
  u64 d = n - 1, r = 0;
  while (!(d & 1)) {
    d >>= 1;
    ++r;
  }
  for (auto a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    if (MillerRobin(n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
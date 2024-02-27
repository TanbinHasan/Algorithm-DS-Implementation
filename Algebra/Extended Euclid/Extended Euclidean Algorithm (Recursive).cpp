/**
 *    author:  Tanbin_Hasan
 *    created: 14.10.2021 00:00:29
**/
#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b, int64_t &x, int64_t &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int64_t x1, y1;
  int64_t G = GCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return G;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int64_t a, b, x, y;
  cin >> a >> b;
  int64_t G = GCD(a, b, x, y);
  cout << x << ' ' << y << ' ' << G << '\n';
  return 0;
}
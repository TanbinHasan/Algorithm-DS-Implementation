/**
 *    author:  Tanbin_Hasan
 *    created: 14.10.2021 00:00:29
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

int egcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1;
  int G = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return G;
}

int egcd(int a, int b, int& x, int& y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, x, y;
  cin >> a >> b;
  int G = egcd(a, b, x, y);
  cout << x << ' ' << y << ' ' << G << '\n';
  return 0;
}
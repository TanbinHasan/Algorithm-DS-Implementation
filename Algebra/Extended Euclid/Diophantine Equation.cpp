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

bool Any_Solution(int a, int b, int c, int& x0, int& y0, int& g) {
  g = egcd(llabs(a), llabs(b), x0, y0);
  if (c % g) {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void shift_solution(int& x, int& y, int a, int b, int cnt) {
  x += cnt * b;
  y -= cnt * a;
}
int All_Solution(int a, int b, int c, int mnx, int mxx, int mny, int mxy) {
  int x, y, g;
  if (!Any_Solution(a, b, c, x, y, g)) return 0;
  a /= g, b /= g;
  int sign_a = a > 0 ? +1 : -1;
  int sign_b = b > 0 ? +1 : -1;
  shift_solution(x, y, a, b, (mnx - x) / b);
  if (x < mnx) shift_solution(x, y, a, b, sign_b);
  if (x > mxx) return 0;
  int lx1 = x;
  shift_solution(x, y, a, b, (mxx - x) / b);
  if (x > mxx) shift_solution(x, y, a, b, -sign_b);
  int rx1 = x;
  shift_solution(x, y, a, b, -(mny - y) / a);
  if (y < mny) shift_solution(x, y, a, b, -sign_a);
  if (y > mxy) return 0;
  int lx2 = x;
  shift_solution(x, y, a, b, -(mxy - y) / a);
  if (y > mxy) shift_solution(x, y, a, b, sign_a);
  int rx2 = x;
  if (lx2 > rx2) swap(lx2, rx2);
  int lx = max(lx1, lx2);
  int rx = min(rx1, rx2);
  if (lx > rx) return 0;
  return (rx - lx) / llabs(b) + 1;
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
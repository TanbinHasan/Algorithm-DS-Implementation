/**
 *    author:  Tanbin_Hasan
 *    created: 17.11.2021 03:21:56
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

double bisection(double a, double b, double c) {
  double l = 0, r = c;
  int iter = 60; // safezone
  while (iter--) {
    double m = (l + r) / 2.0;
    double x = a * m + b * sin(m);
    if (x <= c) l = m;
    else r = m;
  }
  return (l + r) / 2.0l;
}

int main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(6);
  cout << bisection(a, b, c) << '\n';
  return 0;
} 
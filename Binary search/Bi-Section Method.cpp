/**
 *    author:  Tanbin_Hasan
 *    created: 17.11.2021 03:21:56
**/
#include <bits/stdc++.h>

#define int long long
 
using namespace std;

double BiSection(double a, double b, double c) {
  double low = 0, high = c;
  double eps = 1e-7;
  while (high - low >= eps) {
    double mid = (low + high) / 2.0;
    double x = a * mid + b * sin(mid);
    if (x <= c) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return (low + high) / 2;
}

signed main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(6);
  cout << BiSection(a, b, c) << '\n';
  return 0;
} 
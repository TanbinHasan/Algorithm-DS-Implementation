/**
 *    Author  : Tanbin_Hasan
 *    Created : 13.09.2020
**/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int64_t LeadingDigofFact(int n, int k) {
  long double fact = 0;
  for (long double i = 1; i <= n; ++i) fact += log10l(i);
  long double p = fact - floorl(fact + 1e-9);
  long double b = powl(10.0L, p);
  return (int64_t)floorl(b * powl(10.0L, k - 1) + 1e-9);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  cout << LeadingDigofFact(n, k) << '\n';
  return 0;
}
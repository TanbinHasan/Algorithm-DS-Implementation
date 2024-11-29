/**
 *    Author  : Tanbin_Hasan
 *    Created : 13.09.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef long double ld;

const double eps = 1e-9;

i64 ld_fact(int n, int k) {
  ld lg = 0;
  for (int i = 1; i <= n; ++i) lg += log10l(ld(i));
  ld p = lg - floorl(lg + eps);
  ld b = powl(10.0l, p);
  return i64(floorl(b * powl(10.0l, k - 1) + eps));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  cout << ld_fact(n, k) << '\n';
  return 0;
}
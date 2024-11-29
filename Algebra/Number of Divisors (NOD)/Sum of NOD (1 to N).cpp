#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 SNOD(int n) {
  i64 res = 0;
  for (int i = 1; 1LL * i * i <= n; ++i) {
    res += ((n / i) - i);
  }
  res <<= 1;
  res += (i64)sqrtl(n);
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << SNOD(n) << '\n';
  return 0;
}
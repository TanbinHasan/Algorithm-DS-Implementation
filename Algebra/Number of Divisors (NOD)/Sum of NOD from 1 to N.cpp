#include <bits/stdc++.h>

using namespace std;

int SNOD(int n) {
  int res = 0;
  for (int i = 1; i * i <= n; ++i) {
    res += ((n / i) - i);
  }
  res <<= 1;
  res += (int)sqrtl(n);
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
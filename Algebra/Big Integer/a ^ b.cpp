/**
 *    Author : Tanbin_Hasan
 *    Created : 27.07.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

string BigPow(int b, int p) {
  int len = 0, carry = 0;
  vector<int> ar(1, 1);
  while (p--) {
    for (int i = 0; i <= len; ++i) {
      ar[i] = ar[i] * b + carry;
      carry = ar[i] / 10;
      ar[i] %= 10;
    }
    while (carry) {
      ar.push_back(carry % 10);
      carry /= 10, ++len;
    }
  }
  string s;
  for (int i = len; i >= 0; --i)
    s.push_back(ar[i] + '0');
  return s;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int b, p;
  cin >> b >> p;
  cout << BigPow(b, p) << '\n';
  return 0;
}
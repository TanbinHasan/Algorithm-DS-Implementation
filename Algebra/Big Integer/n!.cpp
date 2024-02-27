/**
 *    Author : Tanbin_Hasan
 *    Created : 27.07.2020
**/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string factorial(int n) {
  int len = 0, carry = 0;
  vector<int> ar(1, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= len; ++j) {
      ar[j] = ar[j] * i + carry;
      carry = ar[j] / 10;
      ar[j] %= 10;
    }
    while (carry) {
      ar.push_back(carry % 10);
      carry /= 10;
      ++len;
    }
  }
  string s;
  for (int i = len; i >= 0; --i)
    s.push_back(ar[i] + '0');
  return s;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << factorial(1000);
  return 0;
}
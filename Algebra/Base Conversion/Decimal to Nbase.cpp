/**
 *    author:  T.H666
 *    created: 26.09.2021 22:59:09
**/
#include <bits/stdc++.h>

using namespace std;

string Decimal_to_Nbase(int num, int N) {
  string s;
  do {
    s.push_back((num % N) + '0');
    num /= N;
  } while (num);
  while (s.back() == '0') s.pop_back();
  reverse(s.begin(), s.end());
  return s;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << Decimal_to_Nbase(12, 2);
  return 0;
}
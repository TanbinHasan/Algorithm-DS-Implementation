/**
 *    author:  T.H666
 *    created: 26.09.2021 22:59:09
**/
#include <bits/stdc++.h>

using namespace std;

int Nbase_to_Decimal(string s, int N) {
  reverse(s.begin(), s.end());
  int num = 0;
  for (int i = 0; i < (int)s.size(); ++i)
    num += (int) powl(N, (long double)i) * (int) (s[i] - '0');
  return num;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  cout << Nbase_to_Decimal(s, 2);
  return 0;
}
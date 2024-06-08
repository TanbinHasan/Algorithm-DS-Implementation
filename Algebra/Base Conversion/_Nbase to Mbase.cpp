/**
 *    author:  T.H666
 *    created: 26.09.2021 22:59:09
**/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ui64;

string Nbase_to_Mbase(string s, int N, int M) {
  reverse(s.begin(), s.end());
  ui64 num = 0;
  for (int i = 0; i < (int)s.size(); ++i)
    num += (ui64) powl(N, 1.0l * i) * (ui64) (s[i] - '0');
  s.clear();
  do {
    s.push_back((num % M) + '0');
    num /= M;
  } while (num);
  reverse(s.begin(), s.end());
  return s;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;
  cin >> n;
  cout << Nbase_to_Mbase(n, 10, 2);
  return 0;
}
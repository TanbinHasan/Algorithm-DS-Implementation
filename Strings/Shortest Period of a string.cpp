/**
 *    author:  T.H666
 *    created: 22.08.2022 18:11:43
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

string ShortestPeriod(string s) {
  int n = (int)s.size();
  int m = n;
  for (int i = 2; i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      int j = 0;
      while (j + m / i < m && s[j] == s[j + m / i]) ++j;
      if (j + m / i == m) m /= i;
    }
  }
  return s.substr(0, m);
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  cout << ShortestPeriod(s);
  return 0;
}
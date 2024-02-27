/**
 *    author:  T.H666
 *    created: 04.06.2022 04:32:45
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

string LongestPalindromicPrefix(string s) {
  string rev = s + '?';
  reverse(rev.begin(), rev.end());
  s += rev;
  int n = (int)s.size();
  vector<int> lps(n);
  fill(lps.begin(), lps.end(), 0);
  for (int i = 1; i < n; ++i) {
    int len = lps[i - 1];
    while (len > 0 && s[len] != s[i]) {
      len = lps[len - 1];
    }
    len += (s[i] == s[len]);
    lps[i] = len;
  }
  return s.substr(0, lps[n - 1]);
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  cout << LongestPalindromicPrefix(s);
  return 0;
}
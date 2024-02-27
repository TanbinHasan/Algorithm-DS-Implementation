/**
 *    Author : Tanbin_Hasan
 *    Created : 16.04.2021 14:42:54
**/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> LongestPalSubStr(string &s) {
  int mx_len = 1, len = (int)s.size();
  int low, high;
  pair<int, int> index;
  for (int i = 1; i < len; ++i) {
    // Longest Even Length Palindrome String
    low = i - 1, high = i;
    while (low >= 0 && high < len) {
      if (s[low] != s[high]) break;
      if (high - low + 1 > mx_len) {
        mx_len = high - low + 1;
        index = {low, high};
      }
      --low, ++high;
    }
    // Longest Odd Length Palindrome String
    low = i - 1, high = i + 1;
    while (low >= 0 && high < len) {
      if (s[low] != s[high]) break;
      if (high - low + 1 > mx_len) {
        mx_len = high - low + 1;
        index = {low, high};
      }
      --low, ++high;
    }
  }
  return index;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  auto index = LongestPalSubStr(s);
  cout << "Length = " << index.second - index.first + 1 << '\n';
  for (int i = index.first; i <= index.second; ++i) {
    cout << s[i];
  }
  cout << '\n';
  return 0;
}
/**
 *    Author  : Ador
 *    Created : 27.07.2020
 **/
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
string multiply(string s1, string s2) {
  int a[100000], b[100000], r[100000] = {1}, i, j, k, cnt = 0, carry = 0;
  for (i = s1.size() - 1; i >= 0; --i) a[cnt++] = (s1[i] - 48);
  cnt = 0;
  for (i = s2.size() - 1; i >= 0; --i) b[cnt++] = (s2[i] - 48);
  for (i = 0; i < s1.size(); ++i) {
    k = i - 1;
    for (j = 0; j < s2.size(); ++j) {
      if (!i) {
        r[++k] = (a[i] * b[j] + carry);
        carry = r[k] / 10;
        r[k] %= 10;
      } else {
        r[++k] = (r[k + 1] + a[i] * b[j] + carry);
        carry = r[k] / 10;
        r[k] %= 10;
      }
    }
    while (carry) {
      r[++k] = carry % 10;
      carry /= 10;
    }
  }
  string s;
  for (i = k; i >= 0; --i) s += (r[i] + 48);
  return s;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin) ;
  // freopen("output.txt", "w", stdout) ;
  string s1, s2;
  cin >> s1 >> s2;
  cout << multiply(s1, s2) << "\n";
  return 0;
}

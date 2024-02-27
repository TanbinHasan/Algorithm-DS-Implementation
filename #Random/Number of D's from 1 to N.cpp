#include <bits/stdc++.h>

#define int long long

using namespace std;

// Compute how many d's occur all numbers from 1 to n
int CntD(int n, int d) {
  // Base Case
  if (n < 10) return (n >= d && d > 0);
  // If n does not end in 9, recurse until it does
  string s = to_string(n);
  int c = count(s.begin(), s.end(), '0' + d);
  if ((n % 10) != 9) return c + CntD(n - 1, d);
  return 10LL * CntD(n / 10, d) + (n / 10) + (d > 0);
}

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int l, r;
  cin >> l >> r;
  if (l == 0) {
    cout << CntD(r, 0) + 1 << '\n';
    return;
  }
  cout << CntD(r, 0) - CntD(l - 1, 0) << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
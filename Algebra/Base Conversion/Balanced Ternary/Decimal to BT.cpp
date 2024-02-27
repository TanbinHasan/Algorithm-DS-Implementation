#include <bits/stdc++.h>
#define int long long

using namespace std;

string DecimaltoBT(int n) {
  string ans;
  while (n > 0) {
    int rem = n % 3;
    n /= 3;
    if (rem != 2) ans.push_back(rem + '0');
    if (rem == 2) {
      ans.push_back('Z');
      rem = -1;
      ++n;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << DecimaltoBT(237) << '\n';
  return 0;
}
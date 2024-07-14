/**
 *    author:  Tanbin_Hasan
 *    created: 01.06.2021 18:23:50
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> val(1001, -1);

int MaxLength(vector<int> &ar, int n, int pos) {
  if (val[pos] != -1) return val[pos];
  int ans = 0;
  for (int i = pos + 1; i < n; ++i) {
    if (ar[i] > ar[pos])
      ans = max(ans, MaxLength(ar, n, i));
  }
  return val[pos] = ans + 1;
}

int LengthOfLIS(vector<int> &ar, int n) {
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, MaxLength(ar, n, i));
  return ans;
}

signed main(void) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << LengthOfLIS(ar, n);
  return 0;
}
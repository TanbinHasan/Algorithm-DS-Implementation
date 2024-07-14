/**
 *    author:  Tanbin_Hasan
 *    created: 01.06.2021 20:35:55
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> val(1001);

int LengthOfLIS(vector<int> &ar, int n) {
  for (int pos = n - 1; pos >= 0; --pos) {
    int mxlen = 0;
    for (int i = pos + 1; i < n; ++i)
      if (ar[i] > ar[pos]) mxlen = max(mxlen, val[i]);
    val[pos] = mxlen + 1;
  }
  return *max_element(val.begin(), val.end());
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
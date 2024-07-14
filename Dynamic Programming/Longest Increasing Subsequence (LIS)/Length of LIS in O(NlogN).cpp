/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 14:10:52
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

int LengthOfLIS(vector<int> &ar) {
  vector<int> v;
  for (auto &i : ar) {
    auto it = lower_bound(v.begin(), v.end(), i);
    if (it == (v).end()) v.push_back(i);
    else *it = i;
  }
  return (int)v.size();
}

// LIS in each position in ar
vector<int> LIS(vector<int> &ar, int n) {
  vector<int> len(n);
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), ar[i]);
    if (it == (v).end()) v.push_back(i);
    else *it = i;
    len[i] = (int)v.size();
  }
  return len;
}

signed main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << LengthOfLIS(ar);
  return 0;
}
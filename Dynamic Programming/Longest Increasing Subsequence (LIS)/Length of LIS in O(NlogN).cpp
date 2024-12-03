/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 14:10:52
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int lis_sz(vector<int>& a) {
  vector<int> v;
  for (auto &i : a) {
    auto it = lower_bound(v.begin(), v.end(), i);
    if (it == (v).end()) v.push_back(i);
    else *it = i;
  }
  return (int)v.size();
}

// LIS in each position in ar
vector<int> LIS(vector<int>& a, int n) {
  vector<int> len(n);
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), a[i]);
    if (it == (v).end()) v.push_back(i);
    else *it = i;
    len[i] = (int)v.size();
  }
  return len;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  cout << lis_sz(a);
  return 0;
}
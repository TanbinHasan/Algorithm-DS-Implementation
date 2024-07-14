/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 01:07:04
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> val(1001);
bitset<1001> vis;
vector<int> nxt(1001, -1);

int MaxLength(vector<int> &ar, int n, int pos) {
  if (vis[pos]) return val[pos];
  int ans = 0;
  for (int i = pos + 1; i < n; ++i) {
    if (ar[i] > ar[pos]) {
      int store = MaxLength(ar, n, i);
      if (store > ans) {
        ans = store;
        nxt[pos] = i;
      }
    }
  }
  vis[pos] = 1;
  return val[pos] = ans + 1;
}

vector<int> PathofLIS(vector<int> &ar, int n) {
  int ind = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    int store = MaxLength(ar, n, i);
    if (store > ans) {
      ans = store;
      ind = i;
    }
  }
  vector<int> seq;
  while (ind != -1) {
    seq.push_back(ar[ind]);
    ind = nxt[ind];
  }
  return seq;
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
  auto seq = PathofLIS(ar, n);
  cout << (int)seq.size() << '\n'; // Length of LIS
  for (auto &i : seq) {
    cout << i << " ";
  }
  return 0;
}
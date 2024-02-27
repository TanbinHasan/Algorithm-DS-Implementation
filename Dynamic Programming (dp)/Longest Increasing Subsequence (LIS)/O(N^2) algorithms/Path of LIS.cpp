/**
 *    author:  Tanbin_Hasan
 *    created: 01.06.2021 22:17:44
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> val(1001);
vector<int> nxt(1001, -1);

vector<int> PathOfLIS(vector<int> &ar, int n) {
  for (int pos = n - 1; pos >= 0; --pos) {
    int len = 0;
    for (int i = pos + 1; i < n; ++i) {
      if (ar[i] > ar[pos]) {
        if (val[i] > len) {
          len = val[i];
          nxt[pos] = i;
        }
      }
    }
    val[pos] = len + 1;
  }
  vector<int> seq;
  int x = max_element(val.begin(), val.end()) - (val).begin();
  while (x != -1) {
    seq.push_back(ar[x]);
    x = nxt[x];
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
  auto seq = PathOfLIS(ar, n);
  cout << (int)seq.size() << '\n'; // Length of LIS
  for (auto &i : seq) {
    cout << i << " ";
  }
  return 0;
}
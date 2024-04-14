#include <bits/stdc++.h>

using namespace std;

int subxork(vector<int> &ar, int n, int k) {
  map<int, int> cnt;
  cnt[0] = 1;
  int res = 0, cur = 0;
  for (auto &i : ar) {
    cur ^= i;
    int x = cnt[cur ^ k];
    if (x > 0) res += x;
    ++cnt[cur];
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << subxork(ar, n, 4) << '\n';
  return 0;
}
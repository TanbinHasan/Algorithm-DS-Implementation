#include <bits/stdc++.h>

using namespace std;

int subxork(vector<int>& a, int n, int k) {
  map<int, int> cnt;
  cnt[0] = 1;
  int res = 0, cur = 0;
  for (auto &i : a) {
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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  cout << subxork(a, n, 4) << '\n';
  return 0;
}
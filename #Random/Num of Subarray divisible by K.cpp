#include <bits/stdc++.h>

using namespace std;

int SubCnt(vector<int> &ar, int n, int k) {
  map<int, int> cnt;
  for (auto &i : ar) {
    int x = ((i % k) + k) % k;
    ++cnt[x];
  }
  int ans = cnt[0];
  for (auto &[x, y] : cnt) {
    ans += (y * (y - 1)) / 2LL;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << SubCnt(ar, n, k) << '\n';
  return 0;
}
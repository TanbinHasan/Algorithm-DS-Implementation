#include <bits/stdc++.h>
using namespace std;

typedef long long int i64;

i64 SubCnt(vector<int> &a, int n, int k) {
  map<int, int> cnt;
  for (auto &i : a) {
    int x = ((i % k) + k) % k;
    ++cnt[x];
  }
  i64 ans = cnt[0];
  for (auto &[x, y] : cnt) {
    ans += (1LL * y * (y - 1)) / 2LL;
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
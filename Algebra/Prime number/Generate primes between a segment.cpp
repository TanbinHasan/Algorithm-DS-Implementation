/**
 *    Author  : Tanbin_Hasan
 *    Created : 23.09.2020
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int)1e7 + 1;
bitset<MX> vis(3);  // max(sqrt(r), r - l) + 1, Safe: 1e7

vector<int> GenPrime(int n) {
  if (n < 2) return {};
  vector<int> prime(1, 2);
  for (int i = 4; i <= n; i += 2) vis[i] = 1;
  for (int i = 3; i <= n; i += 2) {
    if (vis[i]) continue;
    prime.push_back(i);
    if (1ULL * i * i > n) continue;
    for (int j = i * i; j <= n; j += 2 * i) vis[j] = 1;
  }
  return prime;
}

auto prime = GenPrime(MX - 1);  // sqrt(r) + 1, Safe: 1e7
vector<i64> GenSegPrime(int l, int r) {
  vector<i64> ans;
  vis.reset();
  for (auto &i : prime) {
    if (1LL * i * i > r) break;
    i64 j = max(1LL * i * i, 1LL * ((l + i - 1) / i) * i);
    for (; j <= r; j += i) vis[j - l] = 1;
  }
  for (i64 i = l + (l == 1); i <= r; ++i)
    if (!vis[i - l]) ans.push_back(i);
  return ans;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin >> l >> r;
  auto prime = GenSegPrime(l, r);
  for (auto &i : prime) {
    cout << i << '\n';
  }
  return 0;
}
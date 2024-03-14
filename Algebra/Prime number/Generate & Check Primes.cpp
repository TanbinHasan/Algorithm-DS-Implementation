/**
 *    Author  : T.H666
 *    Created : 25.10.2020
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int lim = (int) 1e8 + 1;
bitset<lim> vis(3);  // n + 1, Safe: 1e7
vector<int> GenPrime(int n) {
  if (n < 2) return {};
  vector<int> prime(1, 2);
  for (int i = 4; i <= n; i += 2) vis[i] = 1;
  for (int i = 3; i <= n; i += 2) {
    if (vis[i]) continue;
    prime.push_back(i);
    for (int j = i * i; j <= n; j += 2 * i) vis[j] = 1;
  }
  return prime;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto prime = GenPrime(n);
  cout << prime.size() << '\n';
  cout << prime.back() << '\n';
  return 0;
}

#ifdef Normal_Sieve
vector<bool> vis;
vector<int> GenPrime(int n) {
  vector<int> prime;
  if (n > 1) prime.push_back(2);
  vis.assign(n + 1, false);
  vis[0] = vis[1] = true;
  for (uint64_t i = 3; i <= n; i += 2) {
    if (vis[i]) continue;
    prime.push_back(i);
    for (uint64_t j = i * i; j <= n; j += 2 * i) vis[j] = true;
  }
  return prime;
}
#endif

#ifdef Bitwise_Sieve
vector<uint64_t> vis;
vector<int> GenPrime(int n) {
  vector<int> prime;
  if (n > 1) prime.push_back(2);
  vis.assign((n >> 6) + 1, 0);
  vis[0] |= (1ULL << 0), vis[0] |= (1ULL << 1);
  for (uint64_t i = 3; i <= n; i += 2) {
    if (vis[i >> 6] & (1ULL << (i & 63))) continue;
    prime.push_back(i);
    for (uint64_t j = i * i; j <= n; j += 2 * i) vis[j >> 6] |= (1ULL << (j & 63));
  }
  return prime;
}
#endif
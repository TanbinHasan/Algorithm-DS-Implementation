/**
 *    Author  : Tanbin_Hasan
 *    Created : 10.10.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int)1e7 + 5;
bitset<MX> vis(3);

vector<int> GenPrime(int n) {
  vector<int> v;
  if (n > 1) v.push_back(2);
  for (int i = 4; i <= n; i += 2) vis[i] = 1;
  for (int i = 3; i <= n; i += 2) {
    if (vis[i]) continue;
    v.push_back(i);
    if (1LL * i * i > n) continue;
    for (int j = i * i; j <= n; j += 2 * i) vis[j] = 1;
  }
  return v;
}

auto prime = GenPrime(MX - 1); // sqrt(r) + 1, Safe: 1e7

vector<int> segmented_phi(int l, int r) {
  int len = r - l + 1;
  vector<int> v(len), n(len); // calculate coprime, count coprime
  for (int i = 0; i < len; ++i) v[i] = n[i] = l + i;
  for (auto& p : prime) {
    if (1LL * p * p > r) break;
    for (i64 i = max(1LL * p, 1LL * (l + p - 1) / p * p); i <= r; i += p) {
      v[i - l] -= v[i - l] / p;
      while (!(n[i - l] % p)) n[i - l] /= p;
    }
  }
  for (int i = l; i <= r; ++i)
    if (n[i - l] > 1) v[i - l] -= v[i - l] / n[i - l];
  return v;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin >> l >> r;
  auto coprime = segmented_phi(l, r);
  for (auto &i : coprime) {
    cout << i << '\n';
  }
  return 0;
}
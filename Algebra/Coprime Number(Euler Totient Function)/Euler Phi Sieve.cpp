/**
 *    Author  : Tanbin_Hasan
 *    Created : 09.10.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int) 1e7 + 5; // mx(a[i]) + 1
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

auto prime = GenPrime(MX - 1); // N + 1

vector<int> sieve_phi(int n) {
  vector<int> v(n + 1);
  for (int i = 0; i <= n; ++i) v[i] = i;
  for (auto &p : prime)
    for (int i = p; i <= n; i += p) v[i] -= (v[i] / p);
  return v;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto coprime = sieve_phi(n);
  for (int i = 0; i <= n; ++i) {
    cout << coprime[i] << '\n';
  }
  return 0;
}
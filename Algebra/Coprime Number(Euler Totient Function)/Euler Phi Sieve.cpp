/**
 *    Author  : Tanbin_Hasan
 *    Created : 09.10.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int lim = (int) 1e7 + 5; // mx(a[i]) + 1
bitset<lim> check(3);
vector<int> GenPrime(int n) {
  vector<int> prime;
  if (n > 1) prime.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (check[i]) continue;
    prime.push_back(i);
    for (int j = i * i; j <= n; j += 2 * i) check[j] = 1;
  }
  return prime;
}

auto prime = GenPrime(lim - 1); // N + 1
vector<int> GenTotCoprime(int n) {
  vector<int> co(n + 1);
  for (int i = 0; i <= n; ++i) co[i] = i;
  for (auto &p : prime)
    for (int i = p; i <= n; i += p) co[i] -= (co[i] / p);
  return co;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto coprime = GenTotCoprime(n);
  for (int i = 0; i <= n; ++i) {
    cout << coprime[i] << '\n';
  }
  return 0;
}
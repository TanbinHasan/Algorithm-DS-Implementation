/**
 *    Author  : Ador
 *    Created : 04.09.2020
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int)1e6 + 1;  // sqrt(n)
bitset<MX> vis(3);

vector<int> GenPrime(int n) {
  vector<int> v;
  if (n > 1) v.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (vis[i]) continue;
    v.push_back(i);
    if (1LL * i * i > n) continue;
    for (int j = i * i; j <= n; j += 2 * i) vis[j] = 1;
  }
  return v;
}

auto prime = GenPrime(MX - 1);

vector<pair<i64, int>> prime_fact(i64 n) {
  vector<pair<i64, int>> factors;
  for (auto& p : prime) {
    if (1LL * p * p > n) break;
    int cnt = 0;
    while (n % p == 0) ++cnt, n /= p;
    if (cnt) factors.push_back({p, cnt});
  }
  if (n != 1) factors.push_back({n, 1});
  return factors;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n;
  cin >> n;
  auto factors = prime_fact(n);
  for (auto& [p, x] : factors) {
    cout << p << " " << x << "\n";
  }
  return 0;
}
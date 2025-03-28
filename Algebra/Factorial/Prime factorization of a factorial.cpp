/**
 *    Author  : Tanbin_Hasan
 *    Created : 04.09.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = 1e7 + 1; // n + 1
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

vector<pair<int, int>> PrimeFact_fact(int n) {
  vector<pair<int, int>> factors;
  for (auto& p : prime) {
    if (p > n) break;
    int m = n, cnt = 0;
    while (m > 0) {
      cnt += m / p;
      m /= p;
    }
    if (cnt) factors.push_back({p, cnt});
  }
  return factors;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto factors = PrimeFact_fact(n);
  for (auto& [p, x] : factors) {
    cout << p << " " << x << '\n';
  }
  return 0;
}
/**
 *    Author  : Tanbin_Hasan
 *    Created : 11.09.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int)1e6 + 1; // sqrt(base)
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

auto prime = GenPrime(MX - 1);

vector<pair<i64, int>> PrimeFact(i64 n) {
  vector<pair<i64, int>> factors;
  for (auto &i : prime) {
    if (1LL * i * i > n) break;
    if (n % i) continue;
    int cnt = 0;
    while (!(n % i)) ++cnt, n /= i;
    factors.push_back({i, cnt});
  }
  if (n != 1) factors.push_back({n, 1});
  return factors;
}

i64 ctz_fact(i64 n, i64 b) { // number, base
  i64 mn = numeric_limits<i64>::max();
  auto factors = PrimeFact(b);
  for (auto& [p, x] : factors) {
    i64 cnt = 0, m = n;
    while (m > 0) {
      cnt += m / p;
      m /= p;
    }
    mn = min(mn, cnt / x);
  }
  return mn;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n, b;
  cin >> n >> b;
  cout << ctz_fact(n, b) << '\n';
  return 0;
}

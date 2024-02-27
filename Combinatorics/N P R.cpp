/**
 *    Author : Tanbin_Hasan
 *    Created : 28.02.2021
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int md = 1000000007;
const int MX = 1000001;  // safe: n + 1

int BigMod(int b, int p, int md) {
  b %= md;
  int res = 1;
  while (p) {
    if (p & 1) res = ((res % md) * (b % md)) % md;
    b = ((b % md) * (b % md)) % md;
    p >>= 1;
  }
  return res;
}

vector<int> GenFact(int n, int md) {
  vector<int> fact(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    fact[i] = ((fact[i - 1] % md) * (i % md)) % md;
  }
  return fact;
}

auto fact = GenFact(MX, md);

int nPr(int n, int r, int md) {
  vector<int> v(2);
  v[0] = fact[n];
  v[1] = BigMod(fact[n - r], md - 2, md);
  int res = 1;
  for (auto &i : v) {
    res = ((res % md) * (i % md)) % md;
  }
  return res;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  cout << nPr(n, r, md) << '\n';
  return 0;
}

#ifdef Alternative
// It's not for 1 to N
bitset<10000001> check(3); // n + 1, Safe: 1e7
vector<int> GenPrime(int n) {
  vector<int> prime;
  if (n > 1) prime.push_back(2);
  for (uint64_t i = 3; i <= n; i += 2) {
    if (check[i]) continue;
    prime.push_back(i);
    for (uint64_t j = i * i; j <= n; j += 2 * i) check[j] = 1;
  }
  return prime;
}

auto prime = GenPrime(1e7 + 1); // n + 1, Safe: 1e7

int64_t nPr(int n, int r, uint64_t md) {
  map<int,int> cnt;
  for (auto &i : prime) {
    int x = n, y = n - r;
    int freq = 0;
    while (x / i) {
      freq += (x / i - y / i);
      x /= i, y /= i;
    }
    cnt[i] += freq;
  }
  int64_t res = 1;
  for (auto &i : prime)
    while (cnt[i]--) res = ((res % md) * i) % md;
  return res;
}
#endif
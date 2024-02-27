/**
 *    Author  : Ador
 *    Created : 04.09.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int lim = 10000001;
bitset<lim> check(3); // sqrt(n) + 1, Safe: 1e7
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

auto prime = GenPrime(lim - 1); // sqrt(n) + 1, Safe: 1e7

/*
vector<pair<int,int>> PrimeFact(int n) {
  vector<pair<int,int>> factors;
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
*/

vector<int> PrimeFact(int n) {
  vector<int> factors;
  for (auto &i : prime) {
    if (1LL * i * i > n) break;
    if (n % i) continue;
    while (!(n % i)) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n != 1) factors.push_back(n);
  return factors;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto factors = PrimeFact(n);
  for (auto &i : factors) {
    cout << i << ' ';
  }
  return 0;
}
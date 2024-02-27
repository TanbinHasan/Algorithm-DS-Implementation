/**
 *    Author  : Ador
 *    Created : 06.09.2020
 **/
#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bitset<10000001> check(3);  // sqrt(n) + 1, Safe: 1e7
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

auto prime = GenPrime(10000001);  // sqrt(n) + 1
int TotDiv(int64_t n) {
  int res = 1;
  for (auto &i : prime) {
    if (1LL * i * i > n) break;
    int cnt = 1;
    while (!(n % i)) ++cnt, n /= i;
    res *= cnt;
  }
  if (n != 1) res *= 2;
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t n;
  cin >> n;
  cout << TotDiv(n) << '\n';
  return 0;
}

#ifdef Bitwise
vector<int64_t> GenPrime(int n) {
  vector<int64_t> prime;
  if (n > 1) {
    prime.push_back(2);
  }
  vector<uint64_t> check((n >> 6) + 1, 0);
  for (uint64_t i = 3; i <= n; i += 2) {
    if (check[i >> 6] & (1ULL << (i & 63))) {
      continue;
    }
    prime.push_back(i);
    for (uint64_t j = i * i; j <= n; j += 2 * i) {
      check[j >> 6] |= (1ULL << (j & 63));
    }
  }
  return prime;
}

auto prime = GenPrime(1e7 + 1);  // sqrt(n) + 1

int TotDiv(int64_t n) {
  int res = 1;
  for (auto &i : prime) {
    if (i * i > n) {
      break;
    }
    int cnt = 1;
    while (!(n % i)) {
      ++cnt;
      n /= i;
    }
    res *= cnt;
  }
  if (n != 1) {
    res *= 2;
  }
  return res;
}
#endif
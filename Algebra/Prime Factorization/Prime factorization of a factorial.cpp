/**
 *    Author  : Ador
 *    Created : 04.09.2020
**/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

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

auto prime = GenPrime(10000001); // n + 1
vector<pair<int,int>> FactorialPrimeFact(int n) {
  vector<pair<int,int>> factors;
  for (auto &i : prime) {
    int x = n, freq = 0;
    while (x / i) {
      freq += (x / i);
      x /= i;
    }
    if (freq) factors.emplace_back(i, freq);
  }
  return factors;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto factors = FactorialPrimeFact(n);
  for (auto &[x, y] : factors) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
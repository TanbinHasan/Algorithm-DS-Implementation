/**
 *    Author  : Tanbin_Hasan
 *    Created : 09.10.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int lim = 10005; // sqrt(n)
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

auto prime = GenPrime(lim - 1); // sqrt(n)
int TotalCoprime(int n) {
  int coprime = n;
  for (auto &i : prime) {
    if (i * i > n) break;
    if (n % i) continue;
    while (!(n % i)) n /= i;
    coprime -= (coprime / i);
  }
  if (n > 1) coprime -= (coprime / n);
  return coprime;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << TotalCoprime(n) << '\n';
  return 0;
}
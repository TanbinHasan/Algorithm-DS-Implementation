/**
 *    Author  : Tanbin_Hasan
 *    Created : 10.10.2020
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

bitset<10000001> check(3); // n + 1, Safe: 1e7
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

auto prime = GenPrime(10000001); // sqrt(r) + 1, Safe: 1e7

vector<int> GenTotCoprimeSeg(int l, int r) { // etss = Euler Totient Segmented Sieve
  vector<int> coprime(r - l + 1), n(r - l + 1);
  for (int i = 0; i < (r - l + 1); ++i) {
    coprime[i] = l + i;
    n[i] = l + i;
  }
  for (auto &i : prime) {
    if (i * i > r) break;
    for (int j = max(i, ((l + i - 1) / i) * i); j <= r; j += i) {
      coprime[j - l] -= coprime[j - l] / i;
      while (!(n[j - l] % i)) n[j - l] /= i;
    }
  }
  for (int i = l; i <= r; ++i)
    if (n[i - l] > 1) coprime[i - l] -= coprime[i - l] / n[i - l];
  return coprime;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin >> l >> r;
  auto coprime = GenTotCoprimeSeg(l, r);
  for (auto &i : coprime) {
    cout << i << '\n';
  }
  return 0;
}
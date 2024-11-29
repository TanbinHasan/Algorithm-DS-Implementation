/**
 *    Author  : Tanbin_Hasan
 *    Created : 09.10.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int)1e6 + 1; // sqrt(n)
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

i64 phi(i64 n) {
  i64 res = n;
  for (auto& i : prime) {
    if (1LL * i * i > n) break;
    if (n % i) continue;
    while (!(n % i)) n /= i;
    res -= (res / i);
  }
  if (n > 1) res -= (res / n);
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n;
  cin >> n;
  cout << phi(n) << '\n';
  return 0;
}
/*
https://www.hackerrank.com/contests/srbd-code-contest-2024-round-1/challenges/mathematician-montu/problem  
*/
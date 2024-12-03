/**
 *    Author  : Tanbin_Hasan
 *    Created : 06.09.2020
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

i64 SOD(i64 n) {
  i64 res = 1;
  for (auto& p : prime) {
    if (1LL * p * p > n) break;
    i64 sum = 1, prod = 1;
    while (n % p == 0) {
      n /= p;
      prod *= p;
      sum += prod;
    }
    res *= sum;
  }
  if (n != 1) res *= (n + 1);
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n;
  cin >> n;
  cout << SOD(n) << '\n';
  return 0;
}
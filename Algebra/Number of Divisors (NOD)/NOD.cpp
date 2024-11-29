/**
 *    Author  : BlackIce666
 *    Created : 06.09.2020
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = (int)1e6 + 5; // sqrt(n)
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

int NOD(i64 n) {
  int res = 1;
  for (auto &p : prime) {
    if (1LL * p * p > n) break;
    int cnt = 1;
    while (!(n % p)) ++cnt, n /= p;
    res *= cnt;
  }
  if (n != 1) res *= 2;
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n;
  cin >> n;
  cout << NOD(n) << '\n';
  return 0;
}
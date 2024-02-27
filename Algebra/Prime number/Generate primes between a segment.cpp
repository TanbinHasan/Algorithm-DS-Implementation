/**
 *    Author  : Tanbin_Hasan
 *    Created : 23.09.2020
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

bitset<10000001> check(3);  // max(sqrt(r), r - l) + 1, Safe: 1e7
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

auto prime = GenPrime(10000001);  // sqrt(r) + 1, Safe: 1e7
vector<int> GenSegPrime(int l, int r) {
  vector<int> ans;
  check.reset();
  for (auto &i : prime) {
    if (i * i > r) break;
    int j = max(i * i, ((l + i - 1) / i) * i);
    for (; j <= r; j += i) check[j - l] = 1;
  }
  for (int i = l + (l == 1); i <= r; ++i)
    if (!check[i - l]) ans.push_back(i);
  return ans;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r;
  cin >> l >> r;
  auto prime = GenSegPrime(l, r);
  for (auto &i : prime) {
    cout << i << '\n';
  }
  return 0;
}

#ifdef Bitwise
vector<int> GenPrime(int n) {
  vector<int> prime;
  if (n > 1) {
    prime.push_back(2);
  }
  vector<uint> check((n >> 6) + 1, 0);
  for (uint i = 3; i <= n; i += 2) {
    if (check[i >> 6] & (1ULL << (i & 63))) {
      continue;
    }
    prime.push_back(i);
    for (uint j = i * i; j <= n; j += 2 * i) {
      check[j >> 6] |= (1ULL << (j & 63));
    }
  }
  return prime;
}

auto prime = GenPrime((int)1e7L + 1);  // sqrt(r) + 1

vector<int> GenSegPrime(int l, int r) {
  vector<int> ans;
  vector<uint> check(((r - l) >> 6) + 1, 0);
  for (auto &i : prime) {
    if (i * i > r) {
      break;
    }
    int j = max(i * i, (int)ceill((long double)l / i) * i);
    while (j <= r) {
      check[(j - l) >> 6] |= (1ULL << ((j - l) & 63));
      j += i;
    }
  }
  for (int i = (l > 1 ? l : 2); i <= r; ++i) {
    if (!(check[(i - l) >> 6] & (1ULL << ((i - l) & 63)))) {
      ans.push_back(i);
    }
  }
  return ans;
}
#endif
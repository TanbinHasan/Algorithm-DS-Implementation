#include <bits/stdc++.h>

#define int long long

using namespace std;

// md is prime number
vector<int> ModInv(int n, int md) {
  vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (-(md / i) * inv[md % i]) % md;
    inv[i] = (inv[i] + md) % md;
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto v = ModInv(100, 998244353);
  for (auto& i : v) {
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
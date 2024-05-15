#include <bits/stdc++.h>

#define int long long

using namespace std;

const int32_t LIM = (int)1e4 + 1;
const int32_t B = 127657753;
const int32_t mod = 987654319;
int32_t pw[LIM], ipw[LIM];
bool iscalc;

int32_t power(int b, int p, int mod) {
  b %= mod;
  if (b < 0) b += mod;
  int32_t res = 1;
  while (p) {
    if (p & 1) res = (1LL * (res % mod) * (b % mod)) % mod;
    b = (1LL * (b % mod) * (b % mod)) % mod;
    p >>= 1;
  }
  return res;
}

class Hashing {
  bool PreCalc(void) {
    int32_t iB = power(B, mod - 2, mod);
    pw[0] = ipw[0] = 1;
    for (int i = 1; i < LIM; ++i) {
      pw[i] = (1LL * pw[i - 1] * B) % mod;
      ipw[i] = (1LL * ipw[i - 1] * iB) % mod;
    }
    return true;
  }
  int n;
  vector<array<int32_t, 2>> h;  // (normal, rev) hash
 public:
  Hashing(string s) {
    if (!iscalc) iscalc = PreCalc();
    n = (int)s.size();
    h.resize(n);
    for (int i = 0; i < n; ++i) {
      int32_t a = (1LL * s[i] * pw[i]) % mod;
      int32_t b = (1LL * s[i] * pw[n - 1 - i]) % mod;
      h[i][0] = (1LL * a + (i == 0 ? 0 : h[i - 1][0])) % mod;
      h[i][1] = (1LL * b + (i == 0 ? 0 : h[i - 1][1])) % mod;
    }
  }
  int32_t get_h(int l, int r) {
    int32_t x = (h[r][0] - (l == 0 ? 0 : h[l - 1][0])) % mod;
    return (1LL * ((x + mod) % mod) * ipw[l]) % mod;
  }
  int32_t get_rh(int l, int r) {
    int32_t x = (h[r][0] - (l == 0 ? 0 : h[l - 1][1])) % mod;
    return (1LL * ((x + mod) % mod) * ipw[n - 1 - r]) % mod;
  }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  auto ht = Hashing(t).get_h(0, (int)t.size() - 1);
  Hashing h(s);
  int n = (int)s.size(), m = (int)t.size();
  int ans = 0;
  for (int i = 0; i + m - 1 < n; ++i) {
    auto cur = h.get_h(i, i + m - 1);
    if (cur == ht) ++ans;
  }
  cout << ans << '\n';
  return 0;
}
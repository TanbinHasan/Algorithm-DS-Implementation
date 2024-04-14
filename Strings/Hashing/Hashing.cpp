#include <bits/stdc++.h>

#define int long long

using namespace std;

const int32_t LIM = (int)1e6 + 1;  // b + 1
using T = array<int32_t, 2>;
const T mod = {127657753, 987654319};
const T B = {137, 277};
T pw[LIM], ipw[LIM];
bool iscalc;
T operator+(T a, T b) { return {(a[0] + b[0]) % mod[0], (a[1] + b[1]) % mod[1]}; }
T operator-(T a, T b) { return {(a[0] - b[0] + mod[0]) % mod[0], (a[1] - b[1] + mod[1]) % mod[1]}; }
T operator*(T a, T b) { return {(int32_t)(1LL * a[0] * b[0] % mod[0]), (int32_t)(1LL * a[1] * b[1] % mod[1])}; }

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
    T iB = {power(B[0], mod[0] - 2, mod[0]), power(B[1], mod[1] - 2, mod[1])};
    pw[0] = ipw[0] = {1, 1};
    for (int i = 1; i < LIM; ++i) {
      pw[i] = pw[i - 1] * B;
      ipw[i] = ipw[i - 1] * iB;
    }
    return true;
  }
  array<T, 2> f(char c, int i) {
    T a = {(int32_t)(1LL * c * pw[i][0] % mod[0]), (int32_t)(1LL * c * pw[i][1] % mod[1])};
    T b = {(int32_t)(1LL * c * pw[n - 1 - i][0] % mod[0]), (int32_t)(1LL * c * pw[n - 1 - i][1] % mod[1])};
    return {a, b};
  }
  int n;
  vector<array<T, 2>> h;  // (normal, rev) hash
 public:
  Hashing(string s) {
    if (!iscalc) iscalc = PreCalc();
    n = (int)s.size();
    h.resize(n);
    for (int i = 0; i < n; ++i) {
      auto [a, b] = f(s[i], i);
      h[i][0] = a + (i == 0 ? (T){0, 0} : h[i - 1][0]);
      h[i][1] = b + (i == 0 ? (T){0, 0} : h[i - 1][1]);
    }
  }
  T get_h(int l, int r) {
    T x = h[r][0] - (l == 0 ? (T){0, 0} : h[l - 1][0]);
    return x * ipw[l];
  }
  T get_rh(int l, int r) {
    T x = h[r][1] - (l == 0 ? (T){0, 0} : h[l - 1][1]);
    return x * ipw[n - 1 - r];
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
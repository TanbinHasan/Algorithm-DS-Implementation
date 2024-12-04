#include <bits/stdc++.h>
using namespace std;

const int MX = (int)1e5 + 1;  // n + 1
const int K = 3;              // K-Hashing
using H = array<int, K>;
using HH = array<H, 2>;
const H MOD = {127657753, 987654319, 1000000007};  // use K moduli
const H B = {137, 277, 37};                        // use K bases
H P[MX], IP[MX];                                   // power of base and inverse bases

H operator+(H a, H b) {
  H res;
  for (int i = 0; i < K; ++i) res[i] = (a[i] + b[i]) % MOD[i];
  return res;
}
H operator-(H a, H b) {
  H res;
  for (int i = 0; i < K; ++i) res[i] = (a[i] - b[i] + MOD[i]) % MOD[i];
  return res;
}
H operator*(H a, H b) {
  H res;
  for (int i = 0; i < K; ++i) res[i] = (1LL * a[i] * b[i]) % MOD[i];
  return res;
}
H operator*(H a, int b) {
  H res;
  for (int i = 0; i < K; ++i) res[i] = (1LL * a[i] * b) % MOD[i];
  return res;
}
HH operator+(HH a, HH b) { return {a[0] + b[0], a[1] + b[1]}; }

int power(int b, int p, int mod) {
  b %= mod;
  if (b < 0) b += mod;
  int r = 1;
  while (p) {
    if (p & 1) r = (1LL * (r % mod) * (b % mod)) % mod;
    b = (1LL * (b % mod) * (b % mod)) % mod;
    p >>= 1;
  }
  return r;
}

class Hashing {
  int n;
  vector<HH> h;                                                            // (normal, rev) hash
  HH CH(char c, int i) { return {P[i] * (int)c, P[n - 1 - i] * (int)c}; }  // current hash value
 public:
  Hashing(string s) {
    n = (int)s.size();
    h.resize(2 * n);
    for (int i = n; i < 2 * n; ++i) h[i] = CH(s[i - n], i - n);
    for (int i = n - 1; i > 0; --i) h[i] = h[i * 2] + h[i * 2 + 1];
  }
  void update(int i, char c) {
    for (h[i += n] = CH(c, i); i > 1; i /= 2) h[i / 2] = h[i] + h[i ^ 1];
  }
  HH query(int l, int r) {
    HH res = {(H){0, 0}, (H){0, 0}};
    for (l += n, r += (n + 1); l < r; l /= 2, r /= 2) {
      if (l & 1) res = res + h[l++];
      if (r & 1) res = res + h[--r];
    }
    return res;
  }
  H get_h(int l, int r) { return query(l, r)[0] * IP[l]; }
  H get_rh(int l, int r) { return query(l, r)[1] * IP[n - 1 - r]; }
  H concat(H h1, H h2, int sizeof_Hash1) { return h1 + h2 * P[sizeof_Hash1]; }
};

void PreCalculation(void) {
  H IB;
  for (int i = 0; i < K; ++i) IB[i] = power(B[i], MOD[i] - 2, MOD[i]);
  P[0] = IP[0] = {1, 1};
  for (int i = 1; i < MX; ++i) {
    P[i] = P[i - 1] * B;
    IP[i] = IP[i - 1] * IB;
  }
}

// #define MultipleCase
void Solve(int tc) {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  Hashing hs(s);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p;
      char ch;
      cin >> p >> ch;
      hs.update(p - 1, ch);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      auto x = hs.get_h(l, r);
      auto y = hs.get_rh(l, r);
      if (x == y) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalculation();
  int tt = 1;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
  }
  return 0;
}
// https://cses.fi/problemset/task/2420
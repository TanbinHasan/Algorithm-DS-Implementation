#include <bits/stdc++.h>
using namespace std;

const int MX = (int)1e5 + 1;  // n + 1
const int K = 3;              // K-Hashing
using H = array<int, K>;
using HH = array<H, 2>;
const H MOD = {127657753, 987654319, 1000000007};  // use K moduli
const H B = {137, 277, 37};                // use K bases
H P[MX], IP[MX];                       // power of base and inverse bases

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
    h.resize(n);
    h[0] = CH(s[0], 0);
    for (int i = 1; i < n; ++i) h[i] = h[i - 1] + CH(s[i], i);
  }
  H get_h(int l, int r) {
    H x = h[r][0] - (!l ? (H){0, 0} : h[l - 1][0]);
    return x * IP[l];
  }
  H get_rh(int l, int r) {
    H x = h[r][1] - (!l ? (H){0, 0} : h[l - 1][1]);
    return x * IP[n - 1 - r];
  }
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

#define MultipleCase
void Solve(int tc) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string a, b;
  for (int i = 0; i < n; ++i) {
    string c = "01";
    if ((i / k) & 1) swap(c[0], c[1]);
    a.push_back(c[0]);
    b.push_back(c[1]);
  }
  Hashing hs(s), ha(a), hb(b);
  for (int i = 0; i < n; ++i) {
    H l = hs.get_h(i + 1, n - 1), r = hs.get_rh(0, i);
    H cur = l + (r * P[n - i - 1]);
    if (cur == ha.get_h(0, n - 1) || cur == hb.get_h(0, n - 1)) return void(cout << i + 1 << '\n');
  }
  cout << -1 << '\n';
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
// https://codeforces.com/contest/1979/problem/D
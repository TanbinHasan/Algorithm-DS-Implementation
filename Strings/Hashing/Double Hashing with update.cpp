#include <bits/stdc++.h>

#define int long long

using namespace std;

const int32_t LIM = (int)2e5 + 1;  // b + 1
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
  array<T, 2> merge(array<T, 2> a, array<T, 2> b) { return {a[0] + b[0], a[1] + b[1]}; }
  int n;
  vector<array<T, 2>> val;  // (normal, rev) hash
 public:
  Hashing(string s) {
    if (!iscalc) iscalc = PreCalc();
    n = (int)s.size();
    val.resize(2 * n);
    for (int i = n; i < 2 * n; ++i) val[i] = f(s[i - n], i - n);
    for (int i = n - 1; i > 0; --i) val[i] = merge(val[i * 2], val[i * 2 + 1]);
  }
  void update(int i, char ch) {
    for (val[i += n] = f(ch, i); i > 1; i /= 2) val[i / 2] = merge(val[i], val[i ^ 1]);
  }
  array<T, 2> query(int l, int r) {
    array<T, 2> res = {(T){0, 0}, (T){0, 0}};
    for (l += n, r += (n + 1); l < r; l /= 2, r /= 2) {
      if (l & 1) res = merge(res, val[l++]);
      if (r & 1) res = merge(res, val[--r]);
    }
    return res;
  }
  T get_h(int l, int r) { return query(l, r)[0] * ipw[l]; }
  T get_rh(int l, int r) { return query(l, r)[1] * ipw[n - 1 - r]; }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
  return 0;
}
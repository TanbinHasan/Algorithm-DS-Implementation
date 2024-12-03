/**
 *    author:  BlackIce666
 *    created: 24.04.2024 04:07:59
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <int MOD>
class Mint {
 public:
  static const int mod = MOD;
  int v;
  explicit operator int() const { return v; }
  Mint() : v(0) {}
  Mint(i64 _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
  Mint& operator+=(Mint o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  Mint& operator-=(Mint o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  Mint& operator*=(Mint o) {
    v = int(1LL * v * o.v % MOD);
    return *this;
  }
  friend Mint power(Mint b, i64 p) {
    Mint res = 1;
    while (p > 0) {
      if (p & 1) res *= b;
      b *= b;
      p >>= 1;
    }
    return res;
  }
  friend Mint inv(Mint b) {
    assert(b.v != 0);
    return power(b, MOD - 2);
  }
  friend Mint operator+(Mint a, Mint b) { return a += b; }
  friend Mint operator-(Mint a, Mint b) { return a -= b; }
  friend Mint operator*(Mint a, Mint b) { return a *= b; }
};

const int MX = (int)1e6 + 1;
const int MOD = 1000000007;
using mi = Mint<MOD>;
vector<mi> fac(MX), ifac(MX), iv(MX); // factorial, inverse factorial, inverse value

class Combinatorics {
 public:
  mi npr(int n, int r) { return fac[n] * ifac[n - r]; }
  mi ncr(int n, int r) { return npr(n, r) * ifac[r]; }
};

void precalc(void) {
  fac[0] = fac[1] = ifac[0] = ifac[1] = iv[1] = 1;
  for (int i = 2; i < MX; ++i) {
    iv[i] = iv[MOD % i] * -(MOD / i);
    fac[i] = fac[i - 1] * i;
    ifac[i] = ifac[i - 1] * iv[i];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  int tt;
  cin >> tt;
  Combinatorics comb;
  while (tt--) {
    int n, r;
    cin >> n >> r;
    cout << (int)comb.ncr(n, r) << '\n';
  }
  return 0;
}
// https://cses.fi/problemset/task/1079/
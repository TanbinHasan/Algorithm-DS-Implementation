// 08.06.2024 23:58:58
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

using mi = Mint<998244353>;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  i64 n;
  cin >> n;
  i64 d = (int)(to_string(n)).size();
  mi x = power((mi)10, (__int128_t)1 * n * d) - (mi)1;
  mi y = power((mi)10, d) - (mi)1;
  mi res = n * x * inv(y);
  cout << (int) res << '\n';
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
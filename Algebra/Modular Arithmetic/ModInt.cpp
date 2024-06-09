// 08.06.2024 23:58:58
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <int MOD>
class Modular {
 public:
  static const int mod = MOD;
  int v;
  explicit operator int() const { return v; }
  Modular() : v(0) {}
  Modular(i64 _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
  Modular& operator+=(Modular o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  Modular& operator-=(Modular o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  Modular& operator*=(Modular o) {
    v = int(1LL * v * o.v % MOD);
    return *this;
  }
  friend Modular power(Modular b, i64 p) {
    Modular res = 1;
    while (p > 0) {
      if (p & 1) res *= b;
      b *= b;
      p >>= 1;
    }
    return res;
  }
  friend Modular inv(Modular b) {
    assert(b.v != 0);
    return power(b, MOD - 2);
  }
  friend Modular operator+(Modular a, Modular b) { return a += b; }
  friend Modular operator-(Modular a, Modular b) { return a -= b; }
  friend Modular operator*(Modular a, Modular b) { return a *= b; }
};

using mi = Modular<998244353>;

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
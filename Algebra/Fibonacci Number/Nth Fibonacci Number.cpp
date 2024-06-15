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

using mi = Mint<1000000007>;

pair<mi, mi> Fib(i64 n) {
  if (!n) return {0, 1};
  auto [px, py] = Fib(n >> 1);
  mi x = px * ((mi)2 * py - px);
  mi y = px * px + py * py;
  if (n & 1) return {y, x + y};
  return {x, y};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n;
  cin >> n;
  cout << (int)Fib(n).first << '\n';
  return 0;
}
// https://codeforces.com/gym/102644/problem/C
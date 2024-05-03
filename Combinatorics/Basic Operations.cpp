/**
 *    author:  BlackIce666
 *    created: 24.04.2024 04:07:59
 **/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

const int md = 1000000007;
const int lim = (int)3e5 + 1;
vector<int> fact(lim), ifact(lim), inv(lim);
bool iscalc;

class Combinatorics {
  void CalcFacts(void) {
    if (iscalc) return;
    iscalc = true;
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[1] = 1;
    for (int i = 2; i < lim; ++i) {
      inv[i] = (-(md / i) * inv[md % i]) % md;
      inv[i] = (inv[i] + md) % md;
      fact[i] = (fact[i - 1] * i) % md;
      ifact[i] = (ifact[i - 1] * inv[i]) % md;
    }
  }

 public:
  Combinatorics() { CalcFacts(); };
  int nPr(int n, int r) { return (fact[n] * ifact[n - r]) % md; }
  int nCr(int n, int r) { return (nPr(n, r) * ifact[r]) % md; }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Combinatorics comb;
  int n, r;
  cin >> n >> r;
  cout << comb.nCr(n, r) << '\n';
  cout << comb.nPr(n, r) << '\n';
  return 0;
}
/**
 *    author:  BlackIce666
 *    created: 24.04.2024 04:07:59
 **/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MX = (int)3e5 + 1;
vector<int> fact(MX), ifact(MX), inv(MX);
bool iscalc;

class Combinatorics {
  void CalcFacts(void) {
    if (iscalc) return;
    iscalc = true;
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[1] = 1;
    for (int i = 2; i < MX; ++i) {
      inv[i] = (1LL * -(MOD / i) * inv[MOD % i]) % MOD;
      inv[i] = (inv[i] + MOD) % MOD;
      fact[i] = (1LL * fact[i - 1] * i) % MOD;
      ifact[i] = (1LL * ifact[i - 1] * inv[i]) % MOD;
    }
  }

 public:
  Combinatorics() { CalcFacts(); };
  int nPr(int n, int r) { return (1LL * fact[n] * ifact[n - r]) % MOD; }
  int nCr(int n, int r) { return (1LL * nPr(n, r) * ifact[r]) % MOD; }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Combinatorics comb;
  int n, r;
  cin >> n >> r;
  cout << comb.nCr(n, r) << '\n';
  cout << comb.nPr(n, r) << '\n';
  return 0;
}
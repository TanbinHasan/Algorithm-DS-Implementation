#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 cnt_set_bits(i64 n, int k) {
  i64 res = (n >> (k + 1)) << k;
  if ((n >> k) & 1LL) res += (n & ((1LL << k) - 1)) + 1;
  return res;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  i64 n;
  cin >> n;
  cout << cnt_set_bits(n, 4) << '\n'; // check for 4-th bit
  return 0;
}
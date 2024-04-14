/**
 *    author:  BlackIce666
 *    created: 08.04.2024 02:33:03
**/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bitset<30> vis("101010111001110");
  cout << vis.to_ullong() << '\n'; // bitset to unsigned long long
  cout << vis.to_string() << '\n'; // bitset to string
  return 0;
}
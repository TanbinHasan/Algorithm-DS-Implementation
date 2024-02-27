/**
 *    Author  : Ador
 *    Created : 13.08.2020
**/
#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main(void) {
  ull n;
  cin >> n;
  cout << (~n) << "\n";
  return 0;
}

#ifdef DRAFT
  17 = 010001 // It's called bitwise NOT cause it works bit by bit
 ~17 = 101110
 ~17 = -18
  ~0 = -1
  ~1 = -2
  ~5 = -6
~256 = -257

  So , ~x = -(x + 1)

#endif
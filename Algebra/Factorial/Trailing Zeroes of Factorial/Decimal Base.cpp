/**
 *    Author  : Tanbin_Hasan
 *    Created : 11.09.2020
**/
#include <iostream>
#include <algorithm>

using namespace std;

int64_t Trailing0ofFact(int64_t n) {
  auto cnt = [&](int64_t n, int64_t x, int64_t c) {
    while (n) c += (n / x), n /= x;
    return c;
  };
  return min(cnt(n, 2, 0), cnt(n, 5, 0));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t n;
  cin >> n;
  cout << Trailing0ofFact(n) << '\n';
  return 0;
}
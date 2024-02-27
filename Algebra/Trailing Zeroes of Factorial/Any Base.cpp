/**
 *    Author  : Tanbin_Hasan
 *    Created : 11.09.2020
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ;

vector<int32_t> GenPrime(int n) {
  vector<int32_t> prime ;
  if (n > 1) {
    prime.push_back(2) ;
  }
  vector<uint64_t> check((n >> 6) + 1 , 0) ;
  for (uint64_t i = 3 ; i <= n ; i += 2) {
    if (check[i >> 6] & (1ULL << (i & 63))) {
      continue ;
    }
    prime.push_back(i) ;
    for (uint64_t j = i * i ; j <= n ; j += 2 * i) {
      check[j >> 6] |= (1ULL << (j & 63)) ;
    }
  }
  return prime ;
}

int64_t Trailing0ofFact(int64_t n , int64_t base) {
  auto prime = GenPrime((int)sqrtl((long double)base) + 1) ;
  vector <int64_t> ar ;
  for (auto &i : prime) {
    if (base % i) {
      continue ;
    }
    int64_t x = n , no = 0 ;
    while (x) {
      no += (x / i) ;
      x /= i ;
      while (!(base % i)) {
        base /= i ;
      }
    }
    ar.push_back(no) ;
  }
  if (base != 1) {
    int64_t x = n , no = 0 ;
    while (x) {
      no += (x / base) ;
      x /= base ;
    }
    ar.push_back(no) ;
  }
  sort(ar.begin() , ar.end()) ;
  return (ar.empty() ? 0 : ar.front()) ;
}

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  int64_t n , base ;
  cin >> n >> base ;
  cout << Trailing0ofFact(n , base) << '\n' ;
  return 0 ;
}
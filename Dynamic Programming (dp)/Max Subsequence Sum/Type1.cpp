/**
 *    Author : Tanbin_Hasan
 *    Created : 14.04.2021 01:16:25
**/

// Condition : Can't take 2 consecutive numbers .

#include <bits/stdc++.h>

using namespace std ;

vector<long long> value(100001) ; // n + 1
bitset<100001> mark ; // n + 1
long long mx_subseq_sum(vector<long long> &ar , int n , int pos) {
  if (pos >= n) {
    return 0 ;
  }
  if (mark[pos]) {
    return value[pos] ;
  }
  long long choice1 = mx_subseq_sum(ar , n , pos + 2) + ar[pos] ;
  long long choice2 = mx_subseq_sum(ar , n , pos + 1) ;
  mark[pos] = 1 ;
  return value[pos] = max(choice1 , choice2) ;
}

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  int n ;
  cin >> n ;
  vector<long long> ar(n) ;
  for (auto &i : ar) {
    cin >> i ;
  }
  cout << mx_subseq_sum(ar , n , 0) << '\n' ;
  return 0 ;
}
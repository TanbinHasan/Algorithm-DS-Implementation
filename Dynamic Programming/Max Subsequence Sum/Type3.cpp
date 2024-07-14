/**
 *    Author : Tanbin_Hasan
 *    Created : 15.04.2021 19:25:37
**/

// Condition : sub[1] - sub[2] + sub[3] ...... -/+ sub[n]

#include <bits/stdc++.h>

using namespace std ;

vector<long long> value(100001) ;
vector<long long> in1(100001) ;
vector<long long> in2(100001) ;
bitset<100001> mark ;
int sign = 0 , sign2 = 0 ;
long long mx_subseq_sum(vector<long long> &ar , int n , int pos) {
  if (pos >= n) {
    return 0 ;
  }
  if (mark[pos]) {
    return value[pos] ;
  }
  long long choice1 = mx_subseq_sum(ar , n , pos + 1) + ar[pos] ;
  ++sign ;
  long long choice2 = mx_subseq_sum(ar , n , pos + 1) ;
  ++sign2 ;
  mark[pos] = 1 ;
  cout << sign << ' ' << sign2 << ' ' << choice1 << ' ' << choice2 << '\n' ; 
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
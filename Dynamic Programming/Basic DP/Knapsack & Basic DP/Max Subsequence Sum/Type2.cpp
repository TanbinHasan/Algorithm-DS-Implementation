/**
 *    Author : Tanbin_Hasan
 *    Created : 19.06.2021 02:33:01
**/

// Condition : 1 * sub[1] + 2 * sub[2] + ..... + n * sub[n]

#include <bits/stdc++.h>

using namespace std ;

vector<int64_t> val(100001) ;
bitset<100001> mark ;

int64_t MxSubseq(vector<int64_t> &ar , int n , int pos , int index) {
  if (index - 1 > pos) {
    return INT_MIN ;
  }
  if (pos == n || index > n) {
    return 0 ;
  }
  if (mark[pos]) {
    return val[pos] ;
  }
  int64_t choice1 = MxSubseq(ar , n , pos + 1 , index + 1) + index * ar[pos] ;
  int64_t choice2 = MxSubseq(ar , n , pos + 1 , index) ;
  mark[pos] = 1 ;
  return val[pos] = max(choice1 , choice2) ;
}

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  int n ;
  cin >> n ;
  vector<int64_t> ar(n) ;
  for (auto &i : ar) {
    cin >> i ;
  }
  cout << MxSubseq(ar , n , 0 , 1) << '\n' ;
  return 0 ;
}
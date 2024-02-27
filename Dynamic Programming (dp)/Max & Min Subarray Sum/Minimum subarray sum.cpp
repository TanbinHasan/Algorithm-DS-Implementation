/**
 *    author: Tanbin_Hasan
 *    created: 12.05.2021 01:48:52
**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t MinSubArSum(vector<int64_t> &ar) {
  int64_t ans = ar.front(), sum = 0;
  for (auto &i : ar) {
    sum += i;
    ans = min(ans, sum);
    sum = min(sum, 0LL);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << MinSubArSum(ar) << '\n';
  return 0;
}


#ifdef Normal
long long MinSubArSum(vector<long long> &ar) {
  long long ans = ar.front() , sum = 0 , max_sum = 0 ;
  for (auto &i : ar) {
    sum += i ;
    ans = min(ans , sum - max_sum) ;
    max_sum = max(max_sum , sum) ;
  }
  return ans ;
}
#endif
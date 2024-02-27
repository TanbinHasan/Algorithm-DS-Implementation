/**
 *    Author  : Ador
 *    Created : 04.09.2020
**/

#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

int LowerBound(vector<int> &ar, int n, int num) {
  int l = 0, r = n - 1, mid, ans = n;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (ar[mid] >= num) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  sort(ar.begin(), ar.end());
  int w;
  cin >> w;
  if (LowerBound(ar, n, w) == n) {
    cout << w << " isn't found in this array\n";
    return 0;
  }
  cout << "Value of lower_bound of " << w << " = " << ar[LowerBound(ar, n, w)] << "\n";
  cout << "Index of lower_bound of " << w << " = " << LowerBound(ar, n, w) << "\n";
  return 0;
}


#ifdef DRAFT
    For index , lower_bound(start , end , want) - base address
    *** Base address of an array is array name .
    So , to find out index use , lower_bound(ar + x , ar + y , w) - ar

    For value use , *lower_bound(ar + x , ar + y , w)
    x = starting index
    y = ending index
    w = wanted element

    **** 1 ) lower_bound returns only this value / other which is greater than or equal to w (wanted element)
         2 ) If return index == total no. of array element then wanted element isn't available in array

#endif
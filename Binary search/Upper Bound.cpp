/**
 *    Author  : Ador
 *    Created : 04.09.2020
**/
#include <iostream>
#include <vector>

#define int long long

using namespace std;

int UpperBound(vector<int> &ar, int n, int num) {
  int l = 0, r = n - 1, mid, ans = n;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (ar[mid] > num) {
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
  int w;
  cin >> w;
  if (UpperBound(ar, n, w) == n) {
    cout << w << " isn't found in this array\n";
    return 0;
  }
  cout << "Value of upper_bound of " << w << " = " << ar[UpperBound(ar, n, w)] << "\n";
  cout << "Index of upper_bound of " << w << " = " << UpperBound(ar, n, w) << "\n";
  return 0;
}


#ifdef DRAFT
    For index , upper_bound(start , end , want) - base address
    *** Base address of an array is array name .
    So , to find out index use , upper_bound(ar + x , ar + y , w) - ar

    For value use , *upper_bound(ar + x , ar + y , w)
    x = starting index
    y = ending index
    w = wanted element

    **** 1 ) upper_bound returns only this value / other which is greater than w (wanted element)
         2 ) If return index == total no. of array element then wanted element isn't available in array

#endif
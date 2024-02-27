/**
 *    Author  : Ador
 *    Created : 01.09.2020
**/
#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

int BinarySearch(vector<int> &ar, int n, int num) {
  int l = 0, r = n - 1, mid;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (ar[mid] == num) return mid;
    else if (ar[mid] > num) r = mid - 1;
    else l = mid + 1;
  }
  return 0;
}

int32_t main(void) {
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) cin >> i;
  sort(ar.begin(), ar.end());
  int want = BinarySearch(ar, n, 28);
  if (want)
    printf("28 is at the %d no. index of this array . \n", want);
  else
    cout << "Not found\n";
  return 0;
}

#ifdef DRAFT
    In STL,
    binary_search(start, end, wanted number)
    return type : bool
#endif
/**
 *    Author  : Tanbin_Hasan
 *    Created : 25.12.2020
**/

#include <iostream>
#include <vector>

using namespace std;

vector<int64_t> temp((int)1e7); // n + 1
void MergeSort(vector<int64_t> &ar, int low, int high) {
  if (low == high) return;
  int mid = low + (high - low) / 2;
  MergeSort(ar, low, mid);
  MergeSort(ar, mid + 1, high);
  for (int l = low, r = mid + 1, i = low; i <= high; ++i) {
    if (l == mid + 1) temp[i] = ar[r++];
    else if (r == high + 1) temp[i] = ar[l++];
    else if (ar[l] < ar[r]) temp[i] = ar[l++];
    else temp[i] = ar[r++];
  }
  for (int i = low; i <= high; ++i) ar[i] = temp[i];
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
  MergeSort(ar, 0, n - 1);
  for (auto &i : ar) {
    cout << i << ' ';
  }
  return 0;
}
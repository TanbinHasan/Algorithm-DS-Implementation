/**
 *    Author  : Tanbin_Hasan
 *    Created : 25.12.2020
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector<int> t((int)1e7);  // n + 1, temporary array
void MergeSort(vector<int> &a, int low, int high) {
  if (low == high) return;
  int mid = low + (high - low) / 2;
  MergeSort(a, low, mid);
  MergeSort(a, mid + 1, high);
  for (int l = low, r = mid + 1, i = low; i <= high; ++i) {
    if (l == mid + 1) t[i] = a[r++];
    else if (r == high + 1) t[i] = a[l++];
    else if (a[l] < a[r]) t[i] = a[l++];
    else t[i] = a[r++];
  }
  for (int i = low; i <= high; ++i) a[i] = t[i];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  MergeSort(a, 0, n - 1);
  for (auto &i : a) {
    cout << i << ' ';
  }
  return 0;
}
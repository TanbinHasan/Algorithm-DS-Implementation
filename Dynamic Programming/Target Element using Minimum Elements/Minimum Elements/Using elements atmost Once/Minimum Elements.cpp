/**
 *    Author : Tanbin_Hasan
 *    Created : 25.09.2021 01:21:15
**/
#include <bits/stdc++.h>

using namespace std;

int MinElement(vector<int> &ar, int tar) {
  vector<int> val(tar + 1, INT_MAX);
  val[0] = 0;
  for (auto &i : ar) {
    for (int j = tar; j >= i; --j) {
      if (val[j - i] != INT_MAX)
        val[j] = min(val[j], val[j - i] + 1);
    }
  }
  return val[tar];
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << MinElement(ar, target);
  return 0;
}
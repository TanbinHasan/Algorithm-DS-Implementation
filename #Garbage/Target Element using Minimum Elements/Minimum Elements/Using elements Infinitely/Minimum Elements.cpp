/**
 *    Author : Tanbin_Hasan
 *    Created : 30.03.2021 23:55:35
**/
#include <bits/stdc++.h>

using namespace std;

int MinElement(vector<int> &ar, int tar) {
  sort(ar.begin(), ar.end());
  vector<int> val(tar + 1);
  for (int i = 1; i <= tar; ++i) {
    val[i] = INT_MAX - 1;
    for (auto &c : ar) {
      if (i - c < 0) break;
      val[i] = min(val[i], val[i - c] + 1);
    }
  }
  return val[tar];
}

/* int MinElement(vector<int> &ar, int tar) {
  vector<int> val(tar + 1, INT_MAX);
  val[0] = 0;
  for (auto &i : ar) {
    for (int j = i; j <= tar; ++j) {
      if (val[j - i] != INT_MAX)
        val[j] = min(val[j], val[j - i] + 1);
    }
  }
  return val[tar];
} */

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << MinElement(ar, target) << '\n';
  return 0;
}
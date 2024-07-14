/**
 *    Author : Tanbin_Hasan
 *    Created : 31.03.2021 23:41:17
**/
#include <bits/stdc++.h>

using namespace std;

int TotalWay(vector<int> &ar, int tar) {
  sort(ar.begin(), ar.end());
  vector<int> val(tar + 1);
  val[0] = 1;
  for (int i = 1; i <= tar; ++i) {
    for (auto &c : ar) {
      if (i - c < 0) break;
      val[i] = (val[i] + val[i - c]) % 1000000007;
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
  cout << TotalWay(ar, target) << '\n';
  return 0;
}
/**
 *    author: Tanbin_Hasan
 *    created: 12.05.2021 01:44:20
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define int long long

using namespace std;

tuple<int,int,int> MaxSubArSum(vector<int> &ar, int n) {
  tuple<int, int, int> ans(ar.front(), 0, 0);
  auto &[x, y, z] = ans;
  int sum = 0, left = 0;
  for (int i = 0; i < n; ++i) {
    sum += ar[i];
    if (sum > x) {
      x = sum;
      y = left;
      z = i;
    }
    if (sum < 0) {
      sum = 0;
      left = i + 1;
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
  auto [x, y, z] = MaxSubArSum(ar, n);
  cout << x << ' ' << y << ' ' << z << '\n';
  return 0;
}
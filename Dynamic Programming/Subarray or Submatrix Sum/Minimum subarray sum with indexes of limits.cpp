/**
 *    author: Tanbin_Hasan
 *    created: 12.05.2021 01:48:52
 **/
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

tuple<long long, int, int> MinSubArSum(vector<long long> &ar, int n) {
  tuple<long long, int, int> ans(ar.front(), 0, 0);
  auto &[x, y, z] = ans;
  long long sum = 0, left = 0;
  for (int i = 0; i < n; ++i) {
    sum += ar[i];
    if (sum < x) {
      x = sum;
      y = left;
      z = i;
    }
    if (sum > 0) {
      sum = 0;
      left = i + 1;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  auto [x, y, z] = MinSubArSum(ar, n);
  cout << x << ' ' << y << ' ' << z << '\n';
  return 0;
}
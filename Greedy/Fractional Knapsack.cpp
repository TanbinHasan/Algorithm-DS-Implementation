/**
 *    Author  : Tanbin_Hasan
 *    Created : 22.01.2021
**/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int64_t FractionalKnapsack(vector<pair<int, int>> &ar, int64_t space) {
  sort(ar.begin(), ar.end(), [](pair<int,int> a, pair<int,int> b) {
    return (int64_t)a.second * b.first > (int64_t)b.second * a.first;
  });
  int64_t ans = 0, used;
  for (auto &[x, y] : ar) {
    used = min((int64_t)x, space);
    if (!used) return ans;
    space -= used;
    ans += ((long double)y / x) * used;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<pair<int,int>> ar(n);
  for (auto &[x, y] : ar) {
    cin >> x >> y; // x = weight , y = price
  }
  cout << FractionalKnapsack(ar, w) << '\n';
  return 0;
}
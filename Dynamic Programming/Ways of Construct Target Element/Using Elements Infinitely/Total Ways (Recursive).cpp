/**
 *    Author : Tanbin_Hasan
 *    Created : 31.03.2021 23:41:17
**/
#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;
vector<int> val(100001, -1); // target + 1

int TotalWay(vector<int> &ar, int tar) {
  if (tar < 0) return 0;
  if (!tar) return 1;
  if (val[tar] != -1) return val[tar];
  int way = 0;
  for (auto &i : ar) {
    if (tar - i < 0) break;
    int temp = TotalWay(ar, tar - i) % md;
    way = (way + temp) % md;
  }
  return val[tar] = way;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  sort(ar.begin(), ar.end());
  for (auto &i : ar) {
    cin >> i;
  }
  cout << TotalWay(ar, target) << '\n';
  return 0;
}
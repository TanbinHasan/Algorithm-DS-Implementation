/**
 *    Author : Tanbin_Hasan
 *    Created : 30.03.2021 21:39:30
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> val(100001, -1); // target + 1
int TotElements(vector<int> &ar, int tar) {
  if (!tar) return 0;
  if (tar < 0) return INT_MAX - 1;
  if (val[tar] != -1) return val[tar];
  int best = INT_MAX - 1;
  for (auto &i : ar) {
    best = min(best, TotElements(ar, tar - i) + 1);
  }
  return val[tar] = best;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << TotElements(ar, target) << '\n';
  return 0;
}
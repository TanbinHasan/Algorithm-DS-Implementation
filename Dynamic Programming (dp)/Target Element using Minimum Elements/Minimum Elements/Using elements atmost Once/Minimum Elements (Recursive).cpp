/**
 *    Author : Tanbin_Hasan
 *    Created : 17.06.2021 22:30:06
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> val(1001, vector<int>(10010, -1));

int MinElement(vector<int> &ar, int n, int pos, int tar) {
  if (!tar) return 0;
  if (tar < 0 || pos == n) return INT_MAX - 1;
  if (val[pos][tar] != -1) return val[pos][tar];
  int opt1 = MinElement(ar, n, pos + 1, tar - ar[pos]) + 1;
  int opt2 = MinElement(ar, n, pos + 1, tar);
  return val[pos][tar] = min(opt1, opt2);
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << MinElement(ar, n, 0, target);
  return 0;
}
/**
 *    author:  Tanbin_Hasan
 *    created: 24.09.2021 22:10:19
**/
#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;
vector<int> ar(101);
vector<vector<int>> val(101, vector<int>(100001, -1));
// total ways (ordering) using elements infinitely
int TotalWay(int pos, int tar) {
  if (pos <= 0 || tar < 0) return 0;
  if (!tar) return 1;
  if (val[pos][tar] != -1) return val[pos][tar];
  int a = TotalWay(pos - 1, tar);
  int b = TotalWay(pos, tar - ar[pos]);
  return val[pos][tar] = ((a % md) + (b % md)) % md;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, target;
  cin >> n >> target;
  for (int i = 1; i <= n; ++i) {
    cin >> ar[i];
  }
  cout << TotalWay(n, target);
  return 0;
}
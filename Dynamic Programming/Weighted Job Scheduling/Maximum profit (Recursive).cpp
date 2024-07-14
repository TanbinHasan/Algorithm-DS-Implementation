/**
 *    Author : Tanbin_Hasan
 *    Created : 15.04.2021 22:43:34
 **/

/*
  Given N jobs where every job is represented by following three elements of it :
    1 . Start Time
    2 . Finish Time
    3 . Profit or value Associated (>= 0)
    4 . Overlapping between 2 tasks aren't allowed
 */

#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> starts;
vector<int> val(100001, -1); // n + 1

int MxProfit(vector<tuple<int,int,int>> &ar, int n, int pos) {
  if (pos == n) return 0;
  if (val[pos] != -1) return val[pos];
  auto ub = upper_bound(starts.begin(), starts.end(), get<1>(ar[pos])) - (starts).begin();
  int opt1 = MxProfit(ar, n, ub) + get<2>(ar[pos]);
  int opt2 = MxProfit(ar, n, pos + 1);
  return val[pos] = max(opt1, opt2);
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int,int,int>> ar(n);
  starts.clear();
  for (auto &[x, y, z] : ar) {
    cin >> x >> y >> z;
    starts.push_back(x);
  }
  sort(ar.begin(), ar.end());
  sort(starts.begin(), starts.end());
  cout << MxProfit(ar, n, 0) << '\n';
  return 0;
}
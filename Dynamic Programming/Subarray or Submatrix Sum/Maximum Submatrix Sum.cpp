/**
 *    author:  T.H666
 *    created: 07.02.2022 20:02:13
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const i64 INF = (i64)1e15;

/*
Process:
  1. determine prefix sum of all rows
  2. select 1st & last column (left and right of the range actually)
  3. traversing all rows
  4. use kadane algorithm to determine maximum
*/

i64 max_sub_mat_sum(vector<vector<int>>& v, int n, int m) {
  vector<vector<i64>> pref(n, vector<i64>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      pref[i][j] = v[i][j] + (j ? pref[i][j - 1] : 0);
  i64 ans = -INF;
  for (int l = 0; l < m; ++l) {
    for (int r = l; r < m; ++r) {
      vector<int> v;
      for (int i = 0; i < r; ++i) v.push_back(pref[i][r] - (l ? pref[i][l - 1] : 0));
      i64 mx = -INF, sum = 0;
      for (auto& i : v) {
        sum += i;
        mx = max(mx, sum);
        sum = max(0LL, sum);
      }
      ans = max(ans, mx);
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
  for (auto& i : v) {
    for (auto& j : i) {
      cin >> j;
    }
  }
  cout << max_sub_mat_sum(v, n, m) << '\n';
  return 0;
}
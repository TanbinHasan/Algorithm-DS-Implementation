/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 01:07:04
 **/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1001;
int dp[MX][MX];
vector<int> a;
int n;

int lis_len() {
  for (int prv = n; prv >= 0; --prv) {
    for (int i = n - 1; i >= 0; --i) {
      int exclude = dp[i + 1][prv];
      int include = (prv == n || a[i] > a[prv]) ? dp[i + 1][i] + 1 : 0;
      dp[i][prv] = max(exclude, include);
    }
  }
  return dp[0][n];
}

vector<int> path;
void lis_path(int i, int prv) {
  if (i == n) return;
  int exclude = dp[i + 1][prv];
  int include = (prv == n || a[i] > a[prv]) ? dp[i + 1][i] + 1 : 0;
  if (include > exclude) {
    path.push_back(a[i]);
    lis_path(i + 1, i);
  } else lis_path(i + 1, prv);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (auto& i : a) {
    cin >> i;
  }
  memset(dp, 0, sizeof dp);
  cout << lis_len() << '\n';
  lis_path(0, n);
  for (int x : path) {
    cout << x << " ";
  }
  cout << '\n';
  return 0;
}

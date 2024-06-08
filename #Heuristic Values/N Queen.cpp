// 19.05.2024 19:12:06
#include <bits/stdc++.h>
using namespace std;

typedef long long int i64;

// it calculates no. of all attacking queen for all queen
i64 CalculateHeuristic(vector<int> v) {
  int n = (int)v.size();
  i64 heuristic = 0;
  vector<int> row(n), ld(2 * n - 1), rd(2 * n - 1);
  for (int i = 0; i < n; ++i) {
    heuristic += 2LL * (++row[v[i]] - 1);
    heuristic += 2LL * (++ld[v[i] + i] - 1);
    heuristic += 2LL * (++rd[v[i] - i + n - 1] - 1);
  }
  return heuristic;
}

/* int CalculateHeuristic(vector<int> v) {
  int n = (int)v.size(), heuristic = 0;
  vector<int> row(n), ld(2 * n - 1), rd(2 * n - 1);
  for (int x = 0; x < n; ++x) {
    int i = v[x], j = x;
    ++row[i];
    ++ld[i + j];
    ++rd[i - j + n - 1];
  }
  for (int i = 0; i < 2 * n - 1; ++i) {
    if (i < n) heuristic += (row[i] * (row[i] - 1));
    heuristic += (ld[i] * (ld[i] - 1));
    heuristic += (rd[i] * (rd[i] - 1));
  }
  return heuristic;
} */

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& i : v) {
    cin >> i;
  }
  cout << CalculateHeuristic(v) << '\n';
  return 0;
}
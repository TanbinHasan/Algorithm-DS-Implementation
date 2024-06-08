// 19.05.2024 18:57:02
#include <bits/stdc++.h>
using namespace std;

// sum of all manthan distances between required position & current position
int CalculateHeuristic(vector<vector<int>> mat) {
  int heuristic = 0, n = (int)mat.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!mat[i][j]) continue;
      heuristic += llabs(i - mat[i][j] / n);
      heuristic += llabs(j - mat[i][j] % n);
    }
  }
  return heuristic;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> mat(4, vector<int>(4));
  for (auto& i : mat) {
    for (auto& j : i) {
      cin >> j;
    }
  }
  cout << CalculateHeuristic(mat) << '\n';
  return 0;
}
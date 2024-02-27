#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<vector<int>> mat(r, vector<int>(c));
  for (auto& i : mat) {
    for (auto& j : i) {
      cin >> j;
    }
  }
  int x = 0, y = 0;
  while (x < r && y < c) {
    for (int i = y; i < c; ++i) cout << mat[x][i] << " ";
    ++x;
    for (int i = x; i < r; ++i) cout << mat[i][c - 1] << " ";
    --c;
    if (x < r) {
      for (int i = c - 1; i >= y; --i) cout << mat[r - 1][i] << " ";
      --r;
    }
    if (y < c) {
      for (int i = r - 1; i >= x; --i) cout << mat[i][y] << " ";
      ++y;
    }
  }
  return 0;
}
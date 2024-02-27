/**
 *    author:  Tanbin_Hasan
 *    created: 14.09.2021 02:28:31
**/
#include <bits/stdc++.h>

using namespace std;

int row, col;
vector<string> adj(1001); // Safe: 1001 * 1001
vector<bitset<1001>> vis(1001);
vector<pair<int,int>> dxy = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
void DFS(int r, int c) {
  if (r < 0 || c < 0 || r >= row || c >= col || vis[r][c]) return;
  vis[r][c] = 1;
  // cout << r << ' ' << c << '\n';
  for (auto &[dx, dy] : dxy) {
    DFS(r + dx, c + dy);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> row >> col;
  for (int i = 0; i < row; ++i) {
    cin >> adj[i];
  }
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (!vis[i][j]) {
        DFS(i, j);
      }
    }
  }
  return 0;
}
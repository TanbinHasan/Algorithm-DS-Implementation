/**
 *    author:  Tanbin_Hasan
 *    created: 13.09.2021 22:16:41
**/
#include <bits/stdc++.h>

using namespace std;

int row, col;
char adj[1000][1000];
bitset<1000> vis[1000];
pair<int,int> dxy[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void BFS(int r, int c) {
  vis[r][c] = 1;
  queue<pair<int,int>> q;
  q.push({r, c});
  while (!q.empty()) {
    pair<int,int> node = q.front();
    // cout << node.first << ' ' << node.second << '\n';
    q.pop();
    for (auto &[dx, dy] : dxy) {
      auto [x, y] = make_pair(node.first + dx, node.second + dy);
      if (x < 0 || y < 0 || x >= row || y >= col || vis[x][y]) continue;
      vis[x][y] = 1;
      q.push({x, y});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> row >> col;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      cin >> adj[i][j];
    }
  }
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (!vis[i][j]) {
        BFS(i, j);
      }
    }
  }
  return 0;
}
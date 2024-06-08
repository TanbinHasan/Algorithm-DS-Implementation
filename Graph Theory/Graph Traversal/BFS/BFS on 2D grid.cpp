/**
 *    author:  Tanbin_Hasan
 *    created: 28.05.2024 03:04:55
**/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Graph {
  int n, m;
  vector<string> g;
  vector<vector<bool>> vis;
 public:
  Graph(int _n, int _m) {
    n = _n;
    g.resize(n);
    vis.resize(n);
  }
  void add(int u, string s) { g[u] = s; }

  void bfs(int sx, int sy) {
    vis[sx][sy] = 1;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
      auto [ux, uy] = q.front();
      q.pop();
      // cout << g[ux][uy] << " ";
      for (auto& [dx, dy] : adj_moves) {
        int vx = ux + dx, vy = uy + dy;
        if (vx < 0 || vy < 0 || vx >= n || vy >= m || vis[vx][vy]) continue;
        vis[vx][vy] = 1;
        q.push({vx, vy});
      }
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m; // nodes, edges;
  Graph g(n, m);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    g.add(i, s);
  }
  g.bfs(0, 0);
  return 0;
}
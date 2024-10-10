#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj_moves = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Graph {
  int n, m;
  vector<string> g;
  vector<vector<bool>> vis;
 public:
  Graph(int n, int m) : n(n), m(m), g(n), vis(n) {}
  void add(int u, string s) { g[u] = s; }

  void dfs(int ux, int uy) {
    // cout << g[ux][uy] << " ";
    vis[ux][uy] = 1;
    for (auto [dx, dy] : adj_moves) {
      int vx = ux + dx, vy = uy + dy;
      if (vx < 0 || vy < 0 || vx >= n || vy >= m || vis[vx][vy]) continue;
      dfs(vx, vy);
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
  g.dfs(0, 0);
  return 0;
}
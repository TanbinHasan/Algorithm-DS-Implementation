/**
 *    author:  BlackIce666
 *    created: 28.05.2024 03:02:47
**/
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<bool> vis;
 public:
  Graph(int _n) {
    n = _n;
    g.resize(n);
    vis.resize(n);
  }
  void add(int u, int v) { g[u].push_back(v); }

  void dfs(int u) {
    // cout << u << " ";
    vis[u] = 1;
    for (auto v : g[u]) {
      if (vis[v]) continue;
      dfs(v);
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m; // nodes, edges;
  Graph g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g.add(u, v), g.add(v, u);
  }
  g.dfs(1);
  return 0;
}
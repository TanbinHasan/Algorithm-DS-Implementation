/**
 *    author:  Tanbin_Hasan
 *    created: 28.05.2024 03:04:55
**/
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<bool> vis, col;
 public:
  Graph(int n) : g(n), vis(n), col(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  bool bipartite(int u, int c) {
    vis[u] = 1;
    col[u] = c;
    for (auto v : g[u]) {
      if (!vis[v]) {
        if (!bipartite(v, !c)) return false;
      } else if (col[v] == col[u]) return false;
    }
    return true;
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
  cout << ((g.bipartite(1, 0)) ? ("Bipartite") : ("Not Bipartite")) << '\n';
  return 0;
}
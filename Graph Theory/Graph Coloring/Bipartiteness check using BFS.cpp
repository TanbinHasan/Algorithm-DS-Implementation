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
  Graph(int n) : n(n), g(n), vis(n), col(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  bool bipartite(int s) {
    vis[s] = col[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
          col[v] = !col[u];
        } else if (col[v] == col[u]) return false;
      }
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
  cout << ((g.bipartite(1)) ? ("Bipartite") : ("Not Bipartite")) << '\n';
  return 0;
}
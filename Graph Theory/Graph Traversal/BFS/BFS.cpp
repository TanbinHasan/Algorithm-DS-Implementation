/**
 *    author:  Tanbin_Hasan
 *    created: 28.05.2024 03:04:55
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

  void bfs(int s) {
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      // cout << u << " ";
      for (auto v : g[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        q.push(v);
      }
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
  g.bfs(1);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<int> par;
 public:
  vector<bool> vis;
  Graph(int n) : n(n), g(n), vis(n), par(n, -1) {}
  void add(int u, int v) { g[u].push_back(v); }

  bool iscyclic(int s) {
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (!vis[v]) {
          vis[v] = true;
          par[v] = u;
          q.push(v);
        } else if (par[u] != v) return true;
      }
    }
    return false;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m; // nodes, edges
  cin >> n >> m;
  Graph g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g.add(u, v), g.add(v, u);
  }
  for (int i = 0; i < n; ++i) {
    if (g.vis[i]) continue;
    if (g.iscyclic(i)) {
      cout << "Graph contains cycle\n";
      return 0;
    }
  }
  cout << "Graph doesn't contain any cycle\n";
  return 0;
}
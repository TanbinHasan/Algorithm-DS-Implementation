/**
 *    author:  Tanbin_Hasan
 *    created: 14.09.2021 23:56:54
 **/
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;
 public:
  vector<int> sz;
  Graph(int n) : n(n), g(n), sz(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  int dfs(int u, int p = -1) {
  if ((int)g[u].size() == 1 && p != -1) return 0;
  for (auto& v : g[u]) {
    if (v == p) continue;
    sz[u] += (dfs(v, u) + 1);
  }
  return sz[u];
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
    --u, --v;
    g.add(u, v), g.add(v, u);
  }
  g.dfs(0);
  for (int i = 0; i < n; ++i) {
    cout << g.sz[i] << " \n"[i == n - 1];
  }
  return 0;
}
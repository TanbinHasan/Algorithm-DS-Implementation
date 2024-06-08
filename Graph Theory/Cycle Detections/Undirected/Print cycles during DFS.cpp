// 29.05.2024 16:18:43
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<int> col, par;
 public:
  vector<vector<int>> store; // store cycles here
  Graph(int _n) {
    n = _n;
    g.resize(n);
    col.resize(n);
    par.resize(n);
  }
  void add(int u, int v) { g[u].push_back(v); }

  void dfs_cycle(int u, int p = -1) {
    if (col[u] == 2) return;
    if (col[u] == 1) {
      vector<int> v(1, p);
      while (p != u) {
        p = par[p];
        v.push_back(p);
      }
      store.push_back(v);
      return;
    }
    par[u] = p;
    col[u] = 1; // partially visited
    for (auto v : g[u]) {
      if (v == par[u]) continue;
      dfs_cycle(v, u);
    }
    col[u] = 2; // fully visited
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
    --u, --v;
    g.add(u, v), g.add(v, u);
  }
  g.dfs_cycle(1);
  for (auto& v : g.store) {
    for (auto& i : v) {
      cout << i + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}
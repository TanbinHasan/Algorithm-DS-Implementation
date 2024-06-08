#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<int> par;
 public:
  vector<bool> vis;
  Graph(int _n) {
    n = _n;
    g.resize(n);
    vis.resize(n);
    par.resize(n);
  }
  void add(int u, int v) { g[u].push_back(v); }

  int start, end;
  bool iscyclic(int u, int p = -1) {
    vis[u] = 1;
    par[u] = p;
    for (auto v : g[u]) {
      if (v == p) continue;
      if (vis[v]) { // cycle contains u to v
        start = v, end = u;
        return true;
      }
      if (iscyclic(v, u)) return true;
    }
    return false;
  }
  vector<int> findcycle(int u) {
    start = end = -1;
    if (!iscyclic(u)) return {};
    vector<int> cycle;
    cycle.push_back(start);
    while (end != start) {
      cycle.push_back(end);
      end = par[end];
    }
    cycle.push_back(start);
    return cycle;
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
  for (int i = 0; i < n; ++i) {
    if (g.vis[i]) continue;
    auto ans = g.findcycle(i);
    if (!ans.empty()) {
      cout << (int)ans.size() << '\n';
      for (auto& i : ans) {
        cout << i + 1 << " ";
      }
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
// https://cses.fi/problemset/task/1669/
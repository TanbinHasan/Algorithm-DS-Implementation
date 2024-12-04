#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

class Graph {
  int n;
  vector<vector<int>> g;
 public:
  vector<int> par, col;
  Graph(int n) : n(n), g(n), par(n), col(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  int start, end;
  bool iscyclic(int u) {
    col[u] = 1; // partially visited
    for (auto v : g[u]) {
      if (!col[v]) {
        par[v] = u;
        if (iscyclic(v)) return true;
      } else if (col[v] == 1) {
        start = v, end = u;
        return true;
      }
    }
    col[u] = 2; // fully visited
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
    reverse(cycle.begin(), cycle.end());
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
    g.add(u, v);
  }
  for (int i = 0; i < n; ++i) {
    if (g.col[i]) continue;
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
// https://cses.fi/problemset/task/1678/
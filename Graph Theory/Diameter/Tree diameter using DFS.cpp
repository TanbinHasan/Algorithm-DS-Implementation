#include <bits/stdc++.h>
using namespace std;

class Graph {
  vector<vector<int>> g;
  int diameter, mxdis, farnode;
 public:
  Graph(int n) : g(n), diameter(0), mxdis(0), farnode(0) {}
  void add(int u, int v) { g[u].push_back(v); }

  void dfs(int u, int d, int p = -1) {
    if (d > mxdis) {
      mxdis = d;
      farnode = u;
      diameter = max(diameter, mxdis);
    }
    for (auto& v : g[u]) {
      if (v == p) continue;
      dfs(v, d + 1, u);
    }
  }

  int diameter_len(void) {
    dfs(0, 0);
    dfs(farnode, 0);
    return diameter;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  Graph g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v), g.add(v, u);
  }
  cout << g.diameter_len() << '\n';
  return 0;
}
/*
https://cses.fi/problemset/task/1131  
*/
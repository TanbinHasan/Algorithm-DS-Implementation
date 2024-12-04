/**
 *    author:  Tanbin_Hasan
 *    created: 18.09.2021 11:52:39
**/
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<int> down, up;

 public:
  vector<int> ans;
  Graph(int n) : g(n), down(n), up(n), ans(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  void dfs1(int u, int par = -1) {
    down[u] = 0;
    for (auto &v : g[u]) {
      if (v == par) continue;
      dfs1(v, u);
      down[u] = max(down[u], down[v] + 1);
    }
  }

  void dfs2(int u, int par = -1) {
    int mx1 = -1, mx2 = -1;
    for (auto& v : g[u]) {
      if (v == par) continue;
      if (down[v] >= mx1) mx2 = mx1, mx1 = down[v];
      else mx2 = max(mx2, down[v]);
    }
    for (auto& v : g[u]) {
      if (v == par) continue;
      if (mx1 == down[v]) up[v] = max(1 + up[u], 2 + mx2);
      else up[v] = max(1 + up[u], 2 + mx1);
      dfs2(v, u);
    }
    ans[u] = max(down[u], up[u]);
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
  g.dfs1(0);
  g.dfs2(0);
  for (int i = 0; i < n; ++i) {
    cout << g.ans[i] << " \n"[i == n - 1];
  }
  return 0;
}
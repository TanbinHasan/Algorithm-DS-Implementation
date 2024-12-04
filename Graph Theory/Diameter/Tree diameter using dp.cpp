/**
 *    author:  Tanbin_Hasan
 *    created: 16.09.2021 03:06:29
 **/
#include <bits/stdc++.h>

using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;
 
 public:
  int diameter = 0;
  Graph(int n) : g(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  int dfs(int u, int p = -1) {
    if ((int)g[u].size() == 1 && p != -1) return 0;
    int mx1 = -1, mx2 = -1, sz = 0, a = 0, b = 0;
    for (auto& v : g[u]) {
      if (v == p) continue;
      a = dfs(v, u), ++sz;
      if (a >= mx1) mx2 = mx1, mx1 = a;
      else mx2 = max(mx2, a);
    }
    a = mx1 + 1;
    if (sz > 1) b = mx1 + mx2 + 2;
    diameter = max({diameter, a, b});
    return a;
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
  g.dfs(0);
  cout << g.diameter << '\n';
  return 0;
}
/*
https://cses.fi/problemset/task/1131
*/
/**
 *    author:  Tanbin_Hasan
 *    created: 01.09.2021 14:09:47
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

  void dfs(int s) {
    vis[s] = 1;
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      // cout << u << " ";
      for (auto v : g[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        st.push(v);
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
  g.dfs(1);
  return 0;
}
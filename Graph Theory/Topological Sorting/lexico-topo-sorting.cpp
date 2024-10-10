// lexicographically topological sorting (kahn's algorithm)
// if the graph isn't acylic topological sorting doesn't exist
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<int>> g;

 public:
  Graph(int n) : n(n), g(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  vector<int> TopoSorting(void) {
    vector<int> in(n), store;  // # of indegree for each node
    for (int u = 0; u < n; ++u) {
      for (auto& v : g[u]) ++in[v];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int u = 0; u < n; ++u) {
      if (!in[u]) pq.push(u); // no dependencies
    }
    while (!pq.empty()) {
      int u = pq.top();
      pq.pop();
      store.push_back(u);
      for (auto& v : g[u]) {
        if (--in[v] == 0) pq.push(v);
      }
    }
    if ((int)store.size() != n) return {}; // graph contains cycle
    return store;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Graph g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  auto ans = g.TopoSorting();
  if (ans.empty()) {
    cout << "Sandro fails.\n";
    return 0;
  }
  for (auto& i : ans) {
    cout << i + 1 << " ";
  }
  cout << '\n';
  return 0;
}
/*
https://www.spoj.com/problems/TOPOSORT/  
*/
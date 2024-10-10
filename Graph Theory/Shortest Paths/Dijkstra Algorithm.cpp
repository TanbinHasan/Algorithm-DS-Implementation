// 06.06.2024 02:20:13
// single source shortest path
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<pair<int, int>>> g; // node, weight
  vector<int> dis;
 public:
  Graph(int _n) {
    n = _n;
    g.resize(n);
    dis.assign(n, numeric_limits<int>::max());
  }
  void add(int u, int v, int w) { g[u].push_back({v, w}); }

  vector<int> dijkstra(int s) { // s = source
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
      auto [cu, u] = q.top();
      q.pop();
      if (cu != dis[u]) continue;
      for (auto [v, cv] : g[u]) {
        if (dis[u] + cv >= dis[v]) continue;
        dis[v] = dis[u] + cv;
        q.push({dis[v], v});
      }
    }
    return dis;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  Graph g(n); // 0 based
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g.add(u, v, w);
    g.add(v, u, w);
  }
  auto dis = g.dijkstra(0); // source = 0
  for (int i = 0; i < n; ++i) {
    cout << dis[i] << " \n"[i == n - 1];
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int INF = (int)1e9;

class Graph {
  int n;
  vector<vector<int>> g;
  vector<bool> vis;
  vector<int> dis, par;

 public:
  Graph(int n) : g(n), vis(n), dis(n), par(n) {}
  void add(int u, int v) { g[u].push_back(v); }

  int shortest_cycle_len(void) {
    int ans = INF;
    for (int i = 0; i < n; ++i) {
      fill(vis.begin(), vis.end(), false);
      fill(dis.begin(), dis.end(), INF);
      fill(par.begin(), par.end(), -1);
      queue<int> q;
      q.push(i);
      vis[i] = true;
      dis[i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : g[u]) {
          if (!vis[v]) {
            q.push(v);
            vis[v] = true;
            dis[v] = dis[u] + 1;
            par[v] = u;
          } else if (par[u] != v) ans = min(ans, dis[u] + dis[v] + 1);
        }
      }
    }
    return ans;
  }
};

void precalc(void) {}

#define testcase
void solve(int tc) {
  cout << "Case " << tc << ": ";
  int n, m;
  cin >> n >> m;
  Graph g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g.add(u, v), g.add(v, u);
  }
  cout << g.shortest_cycle_len() << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  int tt = 1;
#ifdef testcase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
  }
  return 0;
}
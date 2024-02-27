#include <bits/stdc++.h>

#define int long long

using namespace std;

// if the graph isn't acylic topological sorting doesn't exist
bool cycle;
vector<int> path;
void DFS(vector<vector<int>> &adj, vector<int> &vis, int node) {
  if (vis[node] != -1) return;
  vis[node] = 1;
  for (auto &child : adj[node]) {
    if (vis[child] == 1) cycle = true;
    else if (vis[child] == -1) DFS(adj, vis, child);
    if (cycle) return;
  }
  vis[node] = 2;
  path.push_back(node);
}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    adj[x].push_back(y);
  }
  vector<int> vis(n, -1);
  for (int i = 0; i < n; ++i) {
    if (vis[i] != -1) continue;
    DFS(adj, vis, i);
  }
  if (cycle) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  reverse(path.begin(), path.end());
  for (auto &i : path) {
    cout << i << " ";
  }
  cout << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

// using BFS
bool isCyclic(vector<vector<int>> &adj, int n) {
  vector<bool> vis(n + 1);
  vector<int> par(n + 1, -1);
  for (int s = 1; s <= n; ++s) {
    if (vis[s]) continue;
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto &child : adj[node]) {
        if (!vis[child]) {
          vis[child] = true;
          q.push(child);
          par[child] = node;
        } else if (par[node] != child) return true;
      }
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  bool cycle = isCyclic(adj, n);
  cout << ((cycle) ? ("Yes") : ("No"));
  return 0;
}

#ifdef Using_DFS
// call:  isCyclic(adj, n);
bool DFS(vector<vector<int>> &adj, vector<bool> &vis, int node, int par) {
  vis[node] = true;
  for (auto &child : adj[node]) {
    if (!vis[child]) {
      if (DFS(adj, vis, child, node)) return true;
    } else if (child != par) return true;
  }
  return false;
}

bool isCyclic(vector<vector<int>> &adj, int n) {
  vector<bool> vis(n + 1);
  for (int source = 1; source <= n; ++source) {
    if (vis[source]) continue;
    if (DFS(adj, vis, source, -1)) return true;
  }
  return false;
}
#endif
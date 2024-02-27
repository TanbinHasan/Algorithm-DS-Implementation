/**
 *    author:  Tanbin_Hasan
 *    created: 11.09.2021 00:14:33
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<bool> vis(20001);
vector<int> col(20001);
bool Bipartite(vector<vector<int>> &adj, int node, int c) {
  vis[node] = true;
  col[node] = c;
  for (auto &child : adj[node]) {
    if (vis[child] == false) {
      if (Bipartite(adj, child, c ^ 1) == false) return false;
    } else if (col[child] == col[node]) return false;
  }
  return true;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    if (Bipartite(adj, i, 0) == false) {
      cout << "Not Bipartite\n";
      return 0;
    }
  }
  cout << "Bipartite\n";
  return 0;
}
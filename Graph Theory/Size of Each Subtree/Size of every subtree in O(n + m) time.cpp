/**
 *    author:  Tanbin_Hasan
 *    created: 14.09.2021 23:56:54
 **/
#include <bits/stdc++.h>

using namespace std;

const int MX = (int) 1e5 + 1;
vector<int> sz(MX);

int DFS(vector<vector<int>>& g, int u, int p) {
  if ((int)g[u].size() == 1 && p != -1) return 0;
  for (auto& v : g[u]) {
    if (v == p) continue;
    sz[u] += (DFS(g, v, u) + 1);
  }
  return sz[u];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nodes;
  cin >> nodes;
  vector<vector<int>> adj(nodes);
  for (int i = 0; i < nodes - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  DFS(adj, 1, -1);
  for (int i = 1; i <= nodes; ++i) {
    cout << "Size of subtree " << i << " is: " << sz[i] << '\n';
  }
  return 0;
}
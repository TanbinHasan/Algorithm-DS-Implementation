/**
 *    author:  Tanbin_Hasan
 *    created: 11.08.2021 22:30:29
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(200001); // nodes + 1
bitset<200001> vis; // nodes + 1

void DFS(int node) {
  vis[node] = 1;
  // cout << node << ' ';
  for (auto &child : adj[node]) {
    if (vis[child]) continue;
    DFS(child);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  DFS(1);
  return 0;
}
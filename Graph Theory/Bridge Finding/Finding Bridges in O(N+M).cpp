/**
 *    author:  Tanbin_Hasan
 *    created: 13.08.2021 23:34:53
**/
#include <bits/stdc++.h>

using namespace std;

const int lim = 200001;
vector<vector<int>> adj(lim); // nodes + 1
bitset<lim> vis; // nodes + 1
vector<int> in(lim); // nodes + 1
vector<int> low(lim); // nodes + 1
int cnt, bridges;

void DFS(int node, int par) {
  vis[node] = 1;
  in[node] = low[node] = cnt++;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    if (vis[child]) { // node -> child is a back edge
      low[node] = min(low[node], in[child]);
    } else { // node -> child is a tree edge
      DFS(child, node);
      bridges += (low[child] > in[node]);
      low[node] = min(low[node], low[child]);
    }
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
    adj[y].push_back(x); // if graph is bi-directional
  }
  for (int i = 1; i < nodes + 1; ++i) {
    if (!vis[i]) {
      DFS(i, -1);
    }
  }
  return 0;
}
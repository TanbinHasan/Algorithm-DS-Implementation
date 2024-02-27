/**
 *    author:  Tanbin_Hasan
 *    created: 01.09.2021 14:09:47
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(200001); // nodes + 1
bitset<200001> vis; // nodes + 1

void DFS(int node) {
  vis[node] = 1;
  stack<int> s;
  s.push(node);
  while (!s.empty()) {
    node = s.top();
    s.pop();
    // cout << node << ' ';
    for (auto &child : adj[node]) {
      if (vis[child]) continue;
      vis[child] = 1;
      s.push(child);
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
    adj[y].push_back(x);
  }
  DFS(1);
  return 0;
}
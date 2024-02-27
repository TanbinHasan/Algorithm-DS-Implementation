/**
 *    author:  Tanbin_Hasan
 *    created: 17.09.2021 15:30:03
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int diameter, MxDis, FarNode;
 
void DFS(vector<vector<int>> &adj, int node, int par, int dis) {
  if (dis > MxDis) {
    MxDis = dis;
    FarNode = node;
    diameter = max(diameter, MxDis);
  }
  for (auto &child : adj[node]) {
    if (child == par) continue;
    DFS(adj, child, node, dis + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int nodes, edges;
  cin >> nodes >> edges;
  vector<vector<int>> adj(nodes + 1);
  for (int i = 1; i < nodes; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  DFS(adj, 1, -1, 0);
  DFS(adj, FarNode, -1 , 0);
  cout << diameter;
  return 0;
}
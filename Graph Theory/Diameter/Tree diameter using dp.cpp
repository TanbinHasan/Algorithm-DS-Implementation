/**
 *    author:  Tanbin_Hasan
 *    created: 16.09.2021 03:06:29
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int diameter;
int FindDiameter(vector<vector<int>> &adj, int node, int par) { // par = -1
  if ((int)adj[node].size() == 1 && par != -1) return 0;
  int mx1 = -1, mx2 = -1, sz = 0, a = 0, b = 0;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    ++sz;
    a = FindDiameter(adj, child, node);
    if (a >= mx1) {
      mx2 = mx1, mx1 = a;
    } else mx2 = max(mx2, a);
  }
  a = mx1 + 1;
  if (sz > 1) b = mx1 + mx2 + 2;
  diameter = max({diameter, a, b});
  return a;
}
 
int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int nodes;
  cin >> nodes;
  vector<vector<int>> adj(nodes + 1);
  for (int i = 1; i < nodes; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  FindDiameter(adj, 1, -1);
  cout << diameter;
  return 0;
}
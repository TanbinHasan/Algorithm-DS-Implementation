/**
 *    author:  Tanbin_Hasan
 *    created: 14.09.2021 23:56:54
 **/
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int sz[100001];
void DFS(int node, int par) {
  sz[node] = 1;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    DFS(child, node);
    sz[node] += sz[child];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nodes;
  cin >> nodes;
  for (int i = 0; i < nodes - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  DFS(1, -1);
  for (int i = 1; i <= nodes; ++i) {
    cout << "Size of subtree " << i << " is: " << sz[i] << '\n';
  }
  return 0;
}
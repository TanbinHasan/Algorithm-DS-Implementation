/**
 *    author:  Tanbin_Hasan
 *    created: 18.09.2021 11:52:39
**/
#include <bits/stdc++.h>
 
using namespace std;

vector<vector<int>> adj;
vector<int> down, up, ans;
void dec(int n) {
  adj = vector<vector<int>>(n + 1);
  down = vector<int>(n + 1);
  up = vector<int>(n + 1);
  ans = vector<int>(n + 1);
}

void DFS1(int node, int par) {
  down[node] = 0;
  for (auto &child : adj[node]) {
    if (child == par) continue;
    DFS1(child, node);
    down[node] = max(down[node], down[child] + 1);
  }
}

void DFS2(int node, int par) {
  int mx1(-1), mx2(-1);
  for (auto &child : adj[node]) {
    if (child == par) continue;
    if (down[child] >= mx1) mx2 = mx1, mx1 = down[child];
    else mx2 = max(mx2, down[child]);
  }
  for (auto &child : adj[node]) {
    if (child == par) continue;
    if (mx1 == down[child]) up[child] = max(1 + up[node], 2 + mx2);
    else up[child] = max(1 + up[node], 2 + mx1);
    DFS2(child, node);
  }
  ans[node] = max(down[node], up[node]);
}
/*
From main function:
  DFS1(1, -1);
  DFS2(1, -1);
*/

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int nodes;
  cin >> nodes;
  for (int i = 1; i < nodes; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y), adj[y].push_back(x);
  }
  DFS1(1, -1);
  DFS2(1, -1);
  for (int i = 1; i <= nodes; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}
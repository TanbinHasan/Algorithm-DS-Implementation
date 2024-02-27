#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> vcycle; // it contains all cycles
vector<int> col, par;
void Assign(int n) { // must do in every case
  col = vector<int>(n + 1);
  par = vector<int>(n + 1);
  vcycle.clear();
}
void DFS_Cycle(vector<vector<int>> &adj, int u, int p) {
  if (col[u] == 2) return;
  if (col[u] == 1) {
    vector<int> v(1, p);
    int cur = p;
    while (cur != u) {
      cur = par[cur];
      v.push_back(cur);
    }
    vcycle.push_back(v);
    return;
  }
  par[u] = p;
  col[u] = 1; // partially visited
  for (auto& v : adj[u]) {
    if (v == par[u]) continue;
    DFS_Cycle(adj, v, u);
  }
  col[u] = 2; // fully visited
}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  Assign(n); // must do that in every case
  vector<vector<int>> adj(n + 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (col[i] == 2) continue;
    DFS_Cycle(adj, i, 0);
  }
  for (auto& v : vcycle) {
    for (auto& i : v) {
      cout << i << " ";
    }
    cout << '\n';
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
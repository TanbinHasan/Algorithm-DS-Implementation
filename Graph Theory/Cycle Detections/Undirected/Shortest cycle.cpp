#include <bits/stdc++.h>

#define int long long

using namespace std;

int ShortestCycle(vector<vector<int>> &adj, int n) {
  int ans = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    vector<bool> vis(n + 1);
    vector<int> dis(n + 1, numeric_limits<int32_t>::max());
    vector<int> par(n + 1, -1);
    queue<int> q;
    vis[i] = true;
    q.push(i);
    dis[i] = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto &child : adj[node]) {
        if (!vis[child]) {
          vis[child] = true;
          q.push(child);
          dis[child] = dis[node] + 1;
          par[child] = node;
        } else if (par[node] != child) {
          ans = min(ans, dis[node] + dis[child] + 1);
        }
      }
    }
  }
  return ans;
}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cout << ShortestCycle(adj, n) << '\n';
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
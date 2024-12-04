#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

int MST(vector<vector<pair<int,int>>> &adj, int n) {
  vector<int> mn(n, INF);
  int ans = 0;
  mn[0] = 0;
  set<pair<int,int>> q;
  q.insert({0, 0});
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (q.empty()) return -1; // No MST
    auto [nw, nv] = *(q).begin();
    q.erase((q).begin());
    vis[nv] = true;
    ans += nw;
    for (auto &[cv, cw] : adj[nv]) {
      if (vis[cv] || cw >= mn[cv]) continue;
      q.erase({mn[cv], cv});
      mn[cv] = cw;
      q.insert({mn[cv], cv});
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n);
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  int ans = MST(adj, n);
  if (ans == -1) {
    cout << "NO MST\n";
    return 0;
  }
  cout << ans << '\n';
  return 0;
}
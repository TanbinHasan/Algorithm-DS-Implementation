/**
 *    author:  Tanbin_Hasan
 *    created: 19.12.2021 20:04:08
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> Dijskstra(vector<vector<pair<int, int>>> &adj, int s, int n) {
  vector<int> dis(n + 1, numeric_limits<int32_t>::max());
  dis[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, s});
  while (!q.empty()) {
    auto [nw, nv] = q.top();
    q.pop();
    if (nw != dis[nv]) continue;
    for (auto &[cv, cw] : adj[nv]) {
      if (dis[nv] + cw >= dis[cv]) continue;
      dis[cv] = dis[nv] + cw;
      q.push({dis[cv], cv});
    }
  }
  return dis;
}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n + 1);
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  auto dis = Dijskstra(adj, 1, n);
  if (dis[n] == numeric_limits<int32_t>::max()) {
    cout << "Impossible\n";
    return;
  }
  cout << dis[n] << '\n';
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
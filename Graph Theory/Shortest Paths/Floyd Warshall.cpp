#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n, vector<int>(m));
  vector<vector<int>> dis(n, vector<int>(m));
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    if (g[x][y]) g[x][y] = g[y][x] = min(g[x][y], w);
    else g[x][y] = g[y][x] = w;
  }

  int mx = INF;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (g[i][j]) dis[i][j] = g[i][j];
      else dis[i][j] = mx;
    }
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (dis[x][y] >= mx) {
      cout << -1 << '\n';
      continue;
    }
    cout << dis[x][y] << '\n';
  }
  return 0;
}
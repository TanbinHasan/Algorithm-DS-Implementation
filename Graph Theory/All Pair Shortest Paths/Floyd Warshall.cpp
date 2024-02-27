#include <bits/stdc++.h>
 
#define int long long
#define ll __int128_t
 
using namespace std;
 
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1);
  template <typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void PreCalc(void) {}
 
// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, m, q;
  cin >> n >> m >> q;
  Vec<2, int> adj(n + 1, n + 1);
  Vec<2, int> dis(n + 1, n + 1);
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    if (adj[x][y]) adj[x][y] = adj[y][x] = min(adj[x][y], w);
    else adj[x][y] = adj[y][x] = w;
  }
  int mx = numeric_limits<int>::max() / 2LL;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (adj[i][j]) dis[i][j] = adj[i][j];
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
}
 
int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
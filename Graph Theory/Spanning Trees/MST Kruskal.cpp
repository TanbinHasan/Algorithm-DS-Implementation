#include <bits/stdc++.h>

using namespace std;

class DSU {
 public:
  vector<int> par, size;
  DSU(int n) {
    for (int i = 0; i < n; ++i) par.push_back(i);
    size = vector<int>(n, 1);
  }
  // to find the representative of x
  int get(int x) {
    while (par[x] != x) x = par[x];
    return x;
  }
  bool same(int x, int y) { return get(x) == get(y); }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    par[y] = x;
    return true;
  }
};

using edge = tuple<int, int, int>;
vector<edge> MST(vector<edge> edges, int n) {
  DSU dsu(n);
  sort(edges.begin(), edges.end());
  vector<edge> v;
  for (auto &[w, x, y] : edges) {
    if (!dsu.unite(x, y)) continue;
    v.push_back({x, y, w});
  }
  return v;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<edge> edges;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    edges.push_back({w, x, y});
  }
  auto v = MST(edges, n);
  if (v.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  for (auto &[w, x, y] : v) {
    ans += w;
  }
  cout << ans << '\n';
  return 0;
}
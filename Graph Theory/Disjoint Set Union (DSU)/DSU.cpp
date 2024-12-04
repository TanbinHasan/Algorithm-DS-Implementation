#include <bits/stdc++.h>
using namespace std;

class DSU {
 public:
  vector<int> par, size;
  DSU(int n) : par(n), size(n, 1) { iota(par.begin(), par.end(), 0); }

  // get representive of the component
  int get(int u) {
    while (par[u] != u) u = par[u];
    return u;
  }

  bool same(int u, int v) { return get(u) == get(v); }
  
  bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return false;
    if (size[u] < size[v]) swap(u, v);
    size[u] += size[v];
    par[v] = u;
    return true;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  DSU dsu(n);
  while (q--) {
    int type, u, v;
    cin >> type >> u >> v;
    --u, --v;
    if (type == 0) dsu.unite(u, v);
    else cout << dsu.same(u, v) << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>

#define int long long

using namespace std;

class DSU {
 public:
  vector<int> par, size;
  DSU(int n) {
    for (int i = 0; i < n; ++i) par.push_back(i);
    size = vector<int>(n, 1);
  }
  // get representive of the component
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

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  DSU dsu(n);
  while (q--) {
    int type, x, y;
    cin >> type >> x >> y;
    --x, --y;
    if (type == 0) dsu.unite(x, y);
    else cout << dsu.same(x, y) << '\n';
  }
  return 0;
}
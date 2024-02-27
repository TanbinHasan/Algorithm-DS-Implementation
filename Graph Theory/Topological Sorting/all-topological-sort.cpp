#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<vector<int>> ans;
vector<int> v;
vector<bool> vis;
void Rec(vector<vector<int>> &adj, int n) {
  if ((int)v.size() == n) {
    ans.push_back(v);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    for (auto &child : adj[i])
      if (vis[child]) return; // has dependency
    vis[i] = true;
    v.push_back(i);
    Rec(adj, n);
    vis[i] = false;
    v.pop_back();
  }
}
vector<vector<int>> AllTopoSorting(vector<vector<int>> &adj, int n) {
  v.clear();
  ans.clear();
  vis.assign(n, false);
  Rec(adj, n);
  return ans;
}

// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  auto ans = AllTopoSorting(adj, n);
  for (auto &i : ans) {
    for (auto &j : i) {
      cout << j << " ";
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
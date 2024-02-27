#include <bits/stdc++.h>

#define int long long

using namespace std;

void merge(vector<vector<int>> &adj, int node) {
  int len1 = (int)adj[2 * node].size();
  int len2 = (int)adj[2 * node + 1].size();
  int ind1 = 0, ind2 = 0;
  while (ind1 < len1 && ind2 < len2) {
    if (adj[2 * node][ind1] > adj[2 * node + 1][ind2]) {
      adj[node].push_back(adj[2 * node + 1][ind2]);
      ind2++;
    } else {
      adj[node].push_back(adj[2 * node][ind1]);
      ind1++;
    }
  }
  while (ind1 < len1) {
    adj[node].push_back(adj[2 * node][ind1]);
    ind1++;
  }
  while (ind2 < len2) {
    adj[node].push_back(adj[2 * node + 1][ind2]);
    ind2++;
  }
  return;
}

void build(vector<vector<int>> &adj, vector<int> &ar, int s, int f, int node) {
  if (s == f) {
    adj[node].push_back(ar[s]);
    return;
  }
  int m = (s + f) / 2;
  build(adj, ar, s, m, 2 * node);
  build(adj, ar, m + 1, f, 2 * node + 1);
  merge(adj, node);
  return;
}

int query(vector<vector<int>> &adj, int node, int s, int f, int l, int r) {
  if (s > r || f < l) return 0;
  if (s >= l && f <= r) return adj[node].end() - upper_bound(adj[node].begin(), adj[node].end(), r);
  int m = (s + f) / 2;
  int op1 = query(adj, 2 * node, s, m, l, min(r, m));
  int op2 = query(adj, 2 * node + 1, m + 1, f, max(l, m + 1), r);
  return op1 + op2;
}

// #define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> next_right(n);
  vector<vector<int>> adj(4 * n);
  map<int, int> mp;
  for (int i = n - 1; i >= 0; i--) {
    if (mp[a[i]] == 0) {
      next_right[i] = n;
      mp[a[i]] = i;
    } else {
      next_right[i] = mp[a[i]];
      mp[a[i]] = i;
    }
  }
  build(adj, next_right, 0, n - 1, 1);
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << query(adj, 1, 0, n - 1, l, r) << '\n';
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
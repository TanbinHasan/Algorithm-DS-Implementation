#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> col;
bool BackTrack(vector<vector<int>>& adj, int c, int n, int m) {
  if (c == n) return true;
  for (int i = 0; i < m; ++i) {
    bool ok = true;
    for (auto& child : adj[c]) {
      if (col[child] == i) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    col[c] = i;
    if (BackTrack(adj, c + 1, n, m)) return true;
    col[c] = -1;
  }
  return false;
}

int Mcoloring(vector<vector<int>>& adj, int n, int m) { // n = total nodes, m = total colors
  col.assign(n, -1);
  for (int i = 1; i <= m; ++i) {
    if (BackTrack(adj, 0, n, i)) return i;
  }
  return numeric_limits<int>::max();
}

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int need = Mcoloring(adj, n, 4);
  // cout << need << " ";
  if (need <= 4) {
    cout << need << '\n';
  } else {
    cout << "many\n";
  }
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
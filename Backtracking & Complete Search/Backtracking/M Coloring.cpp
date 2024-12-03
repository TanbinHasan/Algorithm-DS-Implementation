#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector<int> col;
bool BackTrack(vector<vector<int>>& g, int c, int n, int m) {
  if (c == n) return true;
  for (int i = 0; i < m; ++i) {
    bool ok = true;
    for (auto& v : g[c]) {
      if (col[v] == i) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    col[c] = i;
    if (BackTrack(g, c + 1, n, m)) return true;
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
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int need = Mcoloring(g, n, 4);
  // cout << need << " ";
  if (need <= 4) {
    cout << need << '\n';
  } else {
    cout << "many\n";
  }
}

int main(void) {
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
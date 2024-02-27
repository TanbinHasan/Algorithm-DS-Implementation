#include <bits/stdc++.h>

#define int long long

using namespace std;

class SparseTable {
 public:
  vector<vector<vector<int>>> mat;
  SparseTable(vector<vector<int>> &ar, int n, int m) {
    int pw = __lg(min(n, m));
    mat = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(pw + 1)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mat[i][j][0] = ar[i][j];
      }
    }
    for (int p = 1; p <= pw; ++p) {
      int x = (1LL << (p - 1));
      for (int i = 0; i + x < n; ++i) {
        for (int j = 0; j + x < m; ++j) {
          mat[i][j][p] = min({mat[i][j][p - 1], mat[i + x][j][p - 1], mat[i][j + x][p - 1], mat[i + x][j + x][p - 1]});
        }
      }
    }
  }
  int query(int x1, int y1, int x2, int y2) {
    int k = min(x2 - x1 + 1, y2 - y1 + 1);
    int p = __lg(k);
    int mn1 = min(mat[x1][y1][p], mat[x2 - (1LL << p) + 1][y2 - (1LL << p) + 1][p]);
    int mn2 = min(mat[x1][y2 - (1LL << p) + 1][p], mat[x2 - (1LL << p) + 1][y1][p]);
    return min(mn1, mn2);
  }
};

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ar(n, vector<int>(m));
  for (auto &i : ar) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  SparseTable st(ar, n, m);
  auto Valid = [&](int mid) {
    int mx = 1;
    for (int i = 0; i + mid - 1 < n; ++i) {
      for (int j = 0; j + mid - 1 < m; ++j) {
        int x1 = i, y1 = j, x2 = i + mid - 1, y2 = j + mid - 1;
        mx = max(mx, st.query(x1, y1, x2, y2));
      }
    }
    return mx >= mid;
  };
  int low = 1, high = min(n, m), ans = 1;
  while (low <= high) {
    int mid = low + (high - low) / 2LL;
    if (Valid(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << '\n';
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
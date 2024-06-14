/**
 *    author:  T.H666
 *    created: 08.07.2022 03:27:25
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

class SparseTable {
  vector<vector<int>> v;
 public:
  SparseTable(vector<int>& a) {
    int n = (int)a.size();
    int pw = __lg(n);
    v.resize(n, vector<int>(pw + 1));
    for (int i = 0; i < n; ++i) v[i][0] = a[i];
    for (int p = 1; p <= pw; ++p) {
      int x = (1LL << (p - 1));
      for (int i = 0; i + x < n; ++i) {
        v[i][p] = v[i][p - 1] + v[i + x][p - 1];
      }
    }
  }
  int query(int l, int r) {
    int sum = 0;
    int pw = __lg(r - l + 1);
    for (int i = pw; i >= 0; --i) {
      if ((1LL << i) <= r - l + 1) {
        sum += v[l][i];
        l += (1LL << i);
      }
    }
    return sum;
  }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  SparseTable st(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l - 1, r - 1) << '\n';
  }
  return 0;
}
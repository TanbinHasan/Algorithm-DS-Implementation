// 20.01.2023 05:11:27
#include <bits/stdc++.h>

#define int long long

using namespace std;

class SegmentTree {
 public:
  // helper function
  int f(int x, int y) { return (x + y); }
  int n;
  vector<int> val;
  // build the tree
  SegmentTree(vector<int> &v) {
    n = (int)v.size();
    val = vector<int>(2 * n);
    for (int i = n; i < 2 * n; ++i) val[i] = v[i - n];
    for (int i = n - 1; i > 0; --i) val[i] = f(val[i * 2], val[i * 2 + 1]);
  }
  // change value at index i
  void update(int i, int x) {
    for (val[i += n] = x; i > 1; i /= 2) val[i / 2] = f(val[i], val[i ^ 1]);
  }
  // sum on interval [l, r]
  int query(int l, int r) {
    int res = 0;  // careful here
    for (l += n, r += (n + 1); l < r; l /= 2, r /= 2) {
      if (l & 1) res = f(res, val[l++]);
      if (r & 1) res = f(res, val[--r]);
    }
    return res;
  }
};

// #define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int n, q;
  cin >> n >> q;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  SegmentTree st(ar);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      st.update(i - 1, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l - 1, r - 1) << '\n';
    }
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
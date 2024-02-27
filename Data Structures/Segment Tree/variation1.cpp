// Finding the maximum and the number of times it appears
#include <bits/stdc++.h>

#define int long long

using namespace std;

class SegmentTree {
 public:
  // helper function
  pair<int,int> f(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return make_pair(a.first, a.second + b.second);
  }
  int n;
  vector<pair<int,int>> v;
  vector<int> a;
  void build(int p, int cl, int cr) {
    if (cl == cr) {
      v[p] = {a[p], 1};
      return;
    }
    int cm = cl + (cr - cl) / 2;
    build(2 * p, cl, cm);
    build(2 * p + 1, cm + 1, cr);
    v[p] = f(v[2 * p], v[2 * p + 1]);
  }
  SegmentTree(vector<int> &ar) {
    n = (int)ar.size();
    a = ar;
    v = vector<pair<int, int>>(4 * n);
    build(1, 0, n - 1);
  }
  // update value at index pos to val, uf -> update function
  void uf(int p, int cl, int cr, int pos, int val) {
    if (cl == cr) {
      v[p] = {val, 1};
      return;
    }
    int cm = cl + (cr - cl) / 2;
    if (pos <= cm) uf(2 * p, cl, cm, pos, val);
    else uf(2 * p + 1, cm + 1, cr, pos, val);
    v[p] = f(v[2 * p], v[2 * p + 1]);
  }
  void update(int pos, int val) { uf(1, 0, n - 1, pos, val); }
  // sum on interval l to r , qf -> query function
  pair<int, int> qf(int p, int cl, int cr, int l, int r) {
    if (l > r) return {numeric_limits<int>::min(), 0}; // careful in this line
    if (l == cl && r == cr) return v[p];
    int cm = cl + (cr - cl) / 2;
    pair<int,int> left = qf(2 * p, cl, cm, l, min(r, cm));
    pair<int,int> right = qf(2 * p + 1, cm + 1, cr, max(l, cm + 1), r);
    return f(left, right);
  }
  pair<int,int> query(int l, int r) { return qf(1, 0, n - 1, l, r); }
};

// #define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  SegmentTree st(a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      st.update(x - 1, y);
    } else {
      int l, r;
      cin >> l >> r;
      auto [x, y] = st.query(l - 1, r - 1);
      cout << x << " " << y << '\n';
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
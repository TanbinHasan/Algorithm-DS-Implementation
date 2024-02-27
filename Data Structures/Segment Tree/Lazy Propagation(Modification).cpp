#include <bits/stdc++.h>

#define int long long

using namespace std;

class SegmentTree {
 public:
  // helper function
  int f(int x, int y) { return (x + y); }
  // modification function
  int op(int x, int y) { return (x + y); }
  int n;
  vector<int> v, a;
  vector<int> lazy;
  void build(int p, int cl, int cr) {
    if (cl == cr) {
      v[p] = a[cl];
      return;
    }
    int cm = cl + (cr - cl) / 2;
    build(2 * p, cl, cm);
    build(2 * p + 1, cm + 1, cr);
    // v[p] = 0;
  }
  SegmentTree(vector<int> &ar) {
    n = (int)ar.size();
    a = ar;
    v = vector<int>(4 * n);
    lazy = vector<int>(4 * n);
    build(1, 0, n - 1);
  }
  void Push(int p) {
    v[2 * p] = op(v[2 * p], lazy[p]);
    lazy[2 * p] = op(lazy[2 * p], lazy[p]);
    v[2 * p + 1] = op(v[2 * p + 1], lazy[p]);
    lazy[2 * p + 1] = op(lazy[2 * p + 1], lazy[p]);
    lazy[p] = 0;
  }
  // assign value val from l to r, uf -> update function
  void uf(int p, int cl, int cr, int l, int r, int val) {
    if (l > r) return;
    if (l == cl && r == cr) {
      v[p] = op(v[p], val);
      lazy[p] = op(lazy[p], val);
      return;
    }
    Push(p);
    int cm = cl + (cr - cl) / 2;
    uf(2 * p, cl, cm, l, min(r, cm), val);
    uf(2 * p + 1, cm + 1, cr, max(l, cm + 1), r, val);
    v[p] = f(v[2 * p], v[2 * p + 1]);
  }
  void update(int l, int r, int val) { uf(1, 0, n - 1, l, r, val); }
  // sum on interval l to r , qf -> query function
  int qf(int p, int cl, int cr, int l, int r) {
    if (l > r) return 0; // careful in this line
    if (l <= cl && cr <= r) return v[p];
    Push(p);
    int cm = cl + (cr - cl) / 2;
    int left = qf(2 * p, cl, cm, l, min(r, cm));
    int right = qf(2 * p + 1, cm + 1, cr, max(l, cm + 1), r);
    return f(left, right);
  }
  int query(int l, int r) { return qf(1, 0, n - 1, l, r); }
  int get(int p) { return qf(1, 0, n - 1, p, p); }
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
      int l, r, y;
      cin >> l >> r >> y;
      st.update(l - 1, r - 1, y);
    } else {
      int x;
      cin >> x;
      cout << st.get(x - 1) << '\n';
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
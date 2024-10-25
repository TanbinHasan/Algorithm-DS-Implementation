// 22.06.2024 01:48:04
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>  // return type
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T x, T y) {  // change here
    return min(x, y);
  }
  SegmentTree(int _n) : n(_n) { t.assign(4 * n, numeric_limits<int>::max()); }

  void update(int u, int l, int r, int p, int val) {
    if (l == r) return void(t[u] = val);  // change here
    int m = l + (r - l) / 2;
    if (p <= m) update(u << 1, l, m, p, val);
    else update(u << 1 | 1, m + 1, r, p, val);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  void update(int p, int val) { update(1, 0, n - 1, p, val); }
  T query(int u, int l, int r, int L, int R, int p) {
    if (L > R) return 0;
    if (l == r) {
      T res = (t[u] <= p);
      t[u] = numeric_limits<int>::max();
      return res;
    }
    int m = l + (r - l) / 2;
    T res = 0;
    if (t[u << 1] <= p) res += query(u << 1, l, m, L, min(R, m), p);
    if (t[u << 1 | 1] <= p) res += query(u << 1 | 1, m + 1, r, max(m + 1, L), R, p);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
    return res;
  }
  T query(int l, int r, int p) { return query(1, 0, n - 1, l, r, p); }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  SegmentTree<int> st(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, v;
      cin >> p >> v;
      st.update(p, v);
    } else {
      int l, r, p;
      cin >> l >> r >> p;
      cout << st.query(l, r - 1, p) << '\n';
    }
  }
  return 0;
}
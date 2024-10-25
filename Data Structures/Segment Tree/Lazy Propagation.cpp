// 24.10.2024 04:41:19
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>
class SegmentTree {
  int n;
  vector<T> t, lazy;  // tree value, propagation value
 public:
  T combine(T x, T y) {  // change here
    return x + y;
  }
  void build(vector<int>& a, int at, int l, int r) {
    if (l == r) return void(t[at] = a[l]);  // change here
    int m = (l + r) >> 1;
    build(a, at << 1, l, m);
    build(a, at << 1 | 1, m + 1, r);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  SegmentTree(vector<int> a) : n((int)a.size()), t(4 * n), lazy(4 * n) { build(a, 1, 0, n - 1); }

  void propagate(int at, int l, int r) {  // change here
    if (!lazy[at]) return;
    t[at] += 1LL * lazy[at] * (r - l + 1);
    if (l != r) {  // not leaf node
      lazy[at << 1] += lazy[at];
      lazy[at << 1 | 1] += lazy[at];
    }
    lazy[at] = 0;
  }

  void update(int at, int l, int r, int L, int R, T val) {
    propagate(at, l, r);
    if (l > R || r < L) return;  // not in range
    if (L <= l && r <= R) {      // completely inside the range
      lazy[at] = val;
      propagate(at, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(at << 1, l, m, L, R, val);
    update(at << 1 | 1, m + 1, r, L, R, val);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

  T query(int at, int l, int r, int L, int R) {
    propagate(at, l, r);
    if (L <= l && r <= R) return t[at];
    int m = (l + r) >> 1;
    if (m >= R) return query(at << 1, l, m, L, R);
    if (m < L) return query(at << 1 | 1, m + 1, r, L, R);
    return combine(query(at << 1, l, m, L, R), query(at << 1 | 1, m + 1, r, L, R));
  }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  SegmentTree<i64> st(a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.update(l - 1, r - 1, v);
    } else {
      int p;
      cin >> p;
      cout << st.query(p - 1, p - 1) << '\n';
    }
  }
  return 0;
}
// https://cses.fi/problemset/task/1651
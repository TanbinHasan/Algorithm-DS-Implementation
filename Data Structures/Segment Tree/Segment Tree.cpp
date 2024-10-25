// 15.06.2024 14:22:27
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>  // return type
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T x, T y) {  // change here
    return x + y;
  }
  void build(vector<int>& a, int at, int l, int r) {
    if (l == r) return void(t[at] = a[l]);  // change here
    int m = l + (r - l) / 2;
    build(a, at << 1, l, m);
    build(a, at << 1 | 1, m + 1, r);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  SegmentTree(vector<int> a) : n((int)a.size()), t(4 * n) { build(a, 1, 0, n - 1); }

  void update(int at, int l, int r, int p, int val) {
    if (l == r) return void(t[at] = val);  // change here
    int m = l + (r - l) / 2;
    if (p <= m) update(at << 1, l, m, p, val);
    else update(at << 1 | 1, m + 1, r, p, val);
    t[at] = combine(t[at << 1], t[at << 1 | 1]);
  }
  void update(int p, int val) { update(1, 0, n - 1, p, val); }

  T query(int at, int l, int r, int L, int R) {
    if (L <= l && r <= R) return t[at];
    int m = l + (r - l) / 2;
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
      int p, val;
      cin >> p >> val;
      st.update(p, val);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r - 1) << '\n';
    }
  }
  return 0;
}
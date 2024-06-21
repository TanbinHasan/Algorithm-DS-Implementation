// 19.06.2024 02:45:28
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <class T>  // return type
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T x, T y) {  // change here
    return max(x, y);
  }
  void build(vector<int>& a, int u, int l, int r) {
    if (l == r) return void(t[u] = a[l]);  // change here
    int m = l + (r - l) / 2;
    build(a, u << 1, l, m);
    build(a, u << 1 | 1, m + 1, r);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  SegmentTree(vector<int> a) : n((int)a.size()) {
    t.resize(4 * n);
    build(a, 1, 0, n - 1);
  }

  void update(int u, int l, int r, int p, int val) {
    if (l == r) return void(t[u] = val);  // change here
    int m = l + (r - l) / 2;
    if (p <= m) update(u << 1, l, m, p, val);
    else update(u << 1 | 1, m + 1, r, p, val);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  void update(int p, int val) { update(1, 0, n - 1, p, val); }

  T first_above(int x, int ind, int u, int l, int r) {
    if (t[u] < x || ind > r) return -1;
    if (l == r) return (l >= ind) ? l : -1;
    int m = l + (r - l) / 2LL;
    T res = first_above(x, ind, u << 1, l, m);
    if (res == -1) return first_above(x, ind, u << 1 | 1, m + 1, r);
    return res;
  }
  T first_above(int x, int ind) { return first_above(x, ind, 1, 0, n - 1); }
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
      int i, v;
      cin >> i >> v;
      st.update(i, v);
    } else {
      int x, ind;
      cin >> x >> ind;
      cout << st.first_above(x, ind) << '\n';
    }
  }
  return 0;
}
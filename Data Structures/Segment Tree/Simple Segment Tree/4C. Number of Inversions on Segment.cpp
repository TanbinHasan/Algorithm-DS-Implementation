// 21.06.2024 19:02:20
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = 41;
struct node {
  i64 inv = 0;
  i64 cnt[MX] = {0};
};

template <class T>  // return type
class SegmentTree {
  int n;
  vector<T> t;  // tree
 public:
  T combine(T l, T r) {  // change here
    node res;
    res.inv = l.inv + r.inv;
    res.cnt[0] = l.cnt[0] + r.cnt[0];
    i64 prv = r.cnt[0];
    for (int i = 1; i < MX; ++i) {
      res.cnt[i] = l.cnt[i] + r.cnt[i];
      // frequency of bigger numbers in the left * frequency of smaller numbers on the right
      res.inv += (1LL * l.cnt[i] * prv);
      prv += r.cnt[i];
    }
    return res;
  }
  void build(vector<int>& a, int u, int l, int r) {
    if (l == r) return void(t[u].cnt[a[l]] = 1);  // change here
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
    if (l == r) { // change here
      t[u].inv = 0;
      memset(t[u].cnt, 0, sizeof t[u].cnt);
      t[u].cnt[val] = 1;
      return;
    }
    int m = l + (r - l) / 2;
    if (p <= m) update(u << 1, l, m, p, val);
    else update(u << 1 | 1, m + 1, r, p, val);
    t[u] = combine(t[u << 1], t[u << 1 | 1]);
  }
  void update(int p, int val) { update(1, 0, n - 1, p, val); }
  T query(int u, int l, int r, int L, int R) {
    if (L <= l && r <= R) return t[u];
    int m = l + (r - l) / 2;
    if (R <= m) return query(u << 1, l, m, L, R);
    if (m < L) return query(u << 1 | 1, m + 1, r, L, R);
    return combine(query(u << 1, l, m, L, R), query(u << 1 | 1, m + 1, r, L, R));
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
  SegmentTree<node> st(a);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << st.query(l, r).inv << '\n';
    } else {
      int p, v;
      cin >> p >> v;
      st.update(p - 1, v);
    }
  }
  return 0;
}
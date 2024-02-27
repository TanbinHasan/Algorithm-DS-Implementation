#include <bits/stdc++.h>
 
using namespace std;
 
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1);
  template <typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
class SegmentTree {
 public:
  int md;
  // helper function
  int f(int x, int y) {
    int r = (x + y) % md;
    return (r + md) % md;
  }
  int n;
  vector<int> val;
  // build the tree
  SegmentTree() {}
  SegmentTree(vector<int>& v, int mod) {
    md = mod;
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
    int res = 0;
    for (l += n, r += (n + 1); l < r; l /= 2, r /= 2) {
      if (l & 1) res = f(res, val[l++]);
      if (r & 1) res = f(res, val[--r]);
    }
    return res;
  }
};
 
const int lim = (int)2e5 + 5;  // n + 1
const int b1 = 137, b2 = 277;
const int md1 = 998244353, md2 = 1000000007;
vector<int> p0(lim), p1(lim), ip0(lim), ip1(lim);
bool iscalc;
 
int BigMod(int b, int p, int md) {
  b %= md;
  int res = 1;
  while (p) {
    if (p & 1) res = (1LL * (res % md) * (b % md)) % md;
    b = (1LL * (b % md) * (b % md)) % md;
    p >>= 1;
  }
  return res;
}
 
class Hashing {
 public:
  bool PreCalcBase(void) {
    p0[0] = p1[0] = ip0[0] = ip1[0] = 1;
    int ib1 = BigMod(b1, md1 - 2, md1);
    int ib2 = BigMod(b2, md2 - 2, md2);
    for (int i = 1; i < lim; ++i) {
      p0[i] = (1LL * p0[i - 1] * b1) % md1;
      p1[i] = (1LL * p1[i - 1] * b2) % md2;
      ip0[i] = (1LL * ip0[i - 1] * ib1) % md1;
      ip1[i] = (1LL * ip1[i - 1] * ib2) % md2;
    }
    return true;
  }
  int n;
  vector<int> h0, h1, rh0, rh1;
  SegmentTree sh0, sh1, srh0, srh1;
  Hashing(string s) {
    if (!iscalc) iscalc = PreCalcBase();
    n = (int)s.size();
    h0 = h1 = rh0 = rh1 = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      h0[i] = (1LL * (s[i] - 'a' + 1) * p0[i]) % md1;
      h1[i] = (1LL * (s[i] - 'a' + 1) * p1[i]) % md2;
      rh0[i] = (1LL * (s[i] - 'a' + 1) * p0[n - 1 - i]) % md1;
      rh1[i] = (1LL * (s[i] - 'a' + 1) * p1[n - 1 - i]) % md2;
    }
    sh0 = SegmentTree(h0, md1);
    sh1 = SegmentTree(h1, md2);
    srh0 = SegmentTree(rh0, md1);
    srh1 = SegmentTree(rh1, md2);
  }
  array<int, 2> get_h(int l, int r) {
    int d1 = sh0.query(l, r), d2 = sh1.query(l, r);
    int x = (1LL * (d1 + md1) * ip0[l]) % md1;
    int y = (1LL * (d2 + md2) * ip1[l]) % md2;
    return {x, y};
  }
  array<int, 2> get_rh(int l, int r) {
    int d1 = srh0.query(l, r), d2 = srh1.query(l, r);
    int x = (1LL * (d1 + md1) * ip0[n - 1 - r]) % md1;
    int y = (1LL * (d2 + md2) * ip1[n - 1 - r]) % md2;
    return {x, y};
  }
  void update(int pos, char ch) {
    int v0 = (1LL * (ch - 'a' + 1) * p0[pos]) % md1;
    int v1 = (1LL * (ch - 'a' + 1) * p1[pos]) % md2;
    int rv0 = (1LL * (ch - 'a' + 1) * p0[n - 1 - pos]) % md1;
    int rv1 = (1LL * (ch - 'a' + 1) * p1[n - 1 - pos]) % md2;
    sh0.update(pos, v0);
    sh1.update(pos, v1);
    srh0.update(pos, rv0);
    srh1.update(pos, rv1);
  }
};
 
void PreCalc(void) {}
 
// #define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  Hashing hs(s);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p;
      char ch;
      cin >> p >> ch;
      hs.update(p - 1, ch);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      auto x = hs.get_h(l, r);
      auto y = hs.get_rh(l, r);
      if (x == y) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
 
int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
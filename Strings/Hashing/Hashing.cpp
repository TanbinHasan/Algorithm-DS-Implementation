#include <bits/stdc++.h>

using namespace std;

const int lim = (int)1e5 + 5;  // n + 1
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
  Hashing(string s) {
    if (!iscalc) iscalc = PreCalcBase();
    n = (int)s.size();
    h0 = h1 = rh0 = rh1 = vector<int>(n);
    array<int, 2> prv1 = {0, 0}, prv2 = {0, 0};
    for (int i = 0; i < n; ++i) {
      h0[i] = (1LL * (s[i] - 'A' + 1) * p0[i] + prv1[0]) % md1;
      h1[i] = (1LL * (s[i] - 'A' + 1) * p1[i] + prv1[1]) % md2;
      rh0[i] = (1LL * (s[i] - 'A' + 1) * p0[n - 1 - i] + prv2[0]) % md1;
      rh1[i] = (1LL * (s[i] - 'A' + 1) * p1[n - 1 - i] + prv2[1]) % md2;
      prv1 = {h0[i], h1[i]}, prv2 = {rh0[i], rh1[i]};
    }
  }
  array<int, 2> get_h(int l, int r) {
    array<int, 2> prv;
    if (l == 0) prv = {0, 0};
    else prv = {h0[l - 1], h1[l - 1]};
    int x = (1LL * (h0[r] - prv[0] + md1) * ip0[l]) % md1;
    int y = (1LL * (h1[r] - prv[1] + md2) * ip1[l]) % md2;
    return {x, y};
  }
  array<int, 2> get_rh(int l, int r) {
    array<int, 2> prv;
    if (l == 0) prv = {0, 0};
    else prv = {rh0[l - 1], rh1[l - 1]};
    int x = (1LL * (rh0[r] - prv[0] + md1) * ip0[n - 1 - r]) % md1;
    int y = (1LL * (rh1[r] - prv[1] + md2) * ip1[n - 1 - r]) % md2;
    return {x, y};
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  Hashing ha(a);
  Hashing hb(b);
  int l = 1, r = n;
  array<int, 3> ans;
  while (l <= r) {
    int m = l + (r - l) / 2LL;
    map<array<int, 2>, int> cnt1;
    set<array<int, 2>> has;
    array<int, 3> cur = {-1, -1, -1};
    for (int i = 0; i + m - 1 < n; ++i) {
      auto x = ha.get_h(i, i + m - 1);
      has.insert(x);
    }
    for (int i = 0; i + m - 1 < n; ++i) {
      auto x = hb.get_h(i, i + m - 1);
      if (has.count(x)) {
        cur = {1, i, m};
        break;
      }
    }
    if (cur[0] != -1) {
      ans = cur;
      l = m + 1;
    } else r = m - 1;
  }
  if (ans[0] == 1) cout << b.substr(ans[1], ans[2]);
  cout << '\n';
  return 0;
}
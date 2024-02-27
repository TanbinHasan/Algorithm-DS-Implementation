#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T>
class mymap {
 public:
  vector<T> v;
  vector<int> cnt;
  void precal(vector<T> a) {
    sort(a.begin(), a.end());
    int n = (int)a.size();
    v.reserve(n + 1);
    v.push_back(a[0]);
    for (int i = 1; i < n; ++i) if (a[i] != a[i - 1]) v.push_back(a[i]);
    int m = (int)v.size(), j = 0;
    cnt.assign(m, 0);
    for (int i = 0; i < m; ++i) {
      while (j < n) {
        if (a[j] != v[i]) break;
        ++cnt[i], ++j;
      }
    }
  }
  pair<int,int> Bsearch(T x) {
    int l = 0, r = (int)v.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (v[m] == x) return make_pair(cnt[m], m);
      if (v[m] < x) l = m + 1;
      else r = m - 1;
    }
    return make_pair(-1, -1);
  }
  int freq(T x) { return max(0LL, Bsearch(x).first); }
  int index(T x) { return Bsearch(x).second; }
  vector<int> get(void) { return cnt; }
};

// #define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int n;
  cin >> n;
  vector<vector<string>> store(21);
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    int l = (int)x.size();
    store[l].push_back(x);
  }
  vector<mymap<int>> mp(21);
  for (int len = 1; len < 21; ++len) {
    if (store[len].empty()) continue;
    vector<int> v;
    for (auto &i : store[len]) {
      int cur = 0;
      for (int j = 0; j < (int)i.size(); ++j) {
        cur = cur * 10 + (i[j] - '0');
        v.push_back(cur);
      }
    }
    mp[len].precal(v);
  }
  int q;
  cin >> q;
  while (q--) {
    vector<int> v(10), order(10);
    for (int i = 0; i < 10; ++i) {
      cin >> v[i];
      order[v[i]] = i;
    }
    string x;
    cin >> x;
    int ans = 0;
    int len = (int)x.size();
    for (int i = 1; i < len; ++i) ans += (int)store[i].size();
    int cur = 0;
    for (int i = 0; i < len; ++i) {
      int ch = x[i] - '0';
      for (int j = order[ch] - 1; j >= 0; --j) {
        cur = cur * 10 + v[j];
        int x = cur;
        cur /= 10;
        ans += mp[len].freq(x);
      }
      cur = cur * 10 + ch;
    }
    cout << ans << '\n';
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
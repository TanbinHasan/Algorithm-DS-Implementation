#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

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

void PreCalc(void) {}

// Count the number of integers within the range A to B whose digitSum equals to X.
// A, B <= 10^9, X <= 10^5
Vec<3, int> dp;
void rset(void) { dp = Vec<3, int>(11, 2, 92, -1); }

int f(string s, int pos, int IsSmall, int DigitSum, int tar) {
  if (pos == (int)s.size()) return (DigitSum % tar == 0);
  int& ret = dp[pos][IsSmall][DigitSum];
  if (ret != -1) return ret;
  ret = 0;
  int lo = 0;
  int hi = ((IsSmall) ? (9) : (s[pos] - '0'));
  for (int i = lo; i <= hi; ++i) {
    int NewIsSmall = (IsSmall | (i < hi));
    int cur = f(s, pos + 1, NewIsSmall, DigitSum + i, tar);
    ret = (ret + cur);
  }
  return ret;
}

#define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  int a, b;
  cin >> a >> b;
  int x;
  cin >> x;
  if (x > 90) {
    cout << 0 << '\n';
    return;
  }
  rset();
  int r = f(to_string(b), 0, 0, 0, x);
  rset();
  int l = f(to_string(a - 1), 0, 0, 0, x);
  cout << r - l << '\n';
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
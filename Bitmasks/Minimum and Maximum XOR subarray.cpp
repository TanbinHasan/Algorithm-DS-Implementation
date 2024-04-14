#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 50000; // size of the array
const int M = 32; // max size/bit of each element of array
const int K = 2; // total number of characters
int32_t nexts[N * M][K];
int32_t node_cnt;

class Trie {
 public:
  Trie() {
    memset(nexts, -1, sizeof (nexts));
    node_cnt = 0;
  }

  void insert(int n) {
    int cur = 0; // start from the root
    for (int i = M - 1; i >= 0; --i) {
      int x = ((n >> i) & 1LL);
      if (nexts[cur][x] == -1) nexts[cur][x] = ++node_cnt;
      cur = nexts[cur][x];
    }
  }

  int MaxSubXOR(int n) {
    int ans = 0, cur = 0;
    for (int i = M - 1; i >= 0; --i) {
      int x = ((n >> i) & 1LL);
      if (nexts[cur][!x] != -1) cur = nexts[cur][!x], ans |= (1LL << i);
      else cur = nexts[cur][x];
    }
    return ans;
  }

  int MinSubXOR(int n) {
    int ans = 0, cur = 0;
    for (int i = M - 1; i >= 0; --i) {
      int x = ((n >> i) & 1LL);
      if (nexts[cur][x] != -1) cur = nexts[cur][x];
      else cur = nexts[cur][!x], ans |= (1LL << i);
    }
    return ans;
  }
};

pair<int, int> MaxMinSubXOR(vector<int> a) {
  Trie t;
  t.insert(0);
  int mx = numeric_limits<int>::min();
  int mn = numeric_limits<int>::max();
  int x = 0;
  for (auto& i : a) {
    x ^= i;
    mx = max(mx, t.MaxSubXOR(x));
    mn = min(mn, t.MinSubXOR(x));
    t.insert(x);
  }
  return make_pair(mx, mn);
}

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  auto [mx, mn] = MaxMinSubXOR(a);
  cout << mx << " " << mn << '\n';
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
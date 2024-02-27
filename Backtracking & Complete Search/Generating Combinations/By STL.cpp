/**
 *    Author  : Tanbin_Hasan
 *    Created : 12.11.2023 03:57:22
**/
#include <bits/stdc++.h>

using namespace std;

// n >= k
vector<vector<int>> GenComb(int n, int k) {
  vector<vector<int>> comb;
  vector<bool> mark(n);
  fill(mark.begin(), mark.begin() + k, true);
  do {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (mark[i]) v.push_back(i);
    }
    comb.push_back(v);
  } while (prev_permutation(mark.begin(), mark.end()));
  return comb;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto comb = GenComb(n, k);
  for (auto& v : comb) {
    for (auto& i : v) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
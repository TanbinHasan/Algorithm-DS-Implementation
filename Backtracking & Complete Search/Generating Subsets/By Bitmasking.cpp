/**
 *    Author  : Tanbin_Hasan
 *    Created : 13.12.2020
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void SubSets(vector<int>& a, int n) {
  for (int mask = 0; mask < (1LL << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask & (1LL << i)) {
        cout << a[i] << ' ';
      }
    }
    cout << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  SubSets(ar, n);
  return 0;
}
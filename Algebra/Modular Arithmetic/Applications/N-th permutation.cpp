#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

/*
Given a sequence A and a permutation P.
Apply given permuation N times on A. 
*/
template<typename T>
T apply(T a, T p) {
  int n = (int)a.size();
  vector<int> seq(n);
  for (int i = 0; i < n; ++i) seq[i] = a[p[i]];
  return seq;
}

template<typename T>
T NthPermutation(T a, T p, i64 k) {
  int n = (int)a.size();
  while (k) {
    if (k & 1) {
      a = apply<T>(a, p);
    }
    p = apply<T>(p, p);
    k >>= 1;
  }
  return a;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> p = {1, 2, 4, 3, 0};
  auto ans = NthPermutation<vector<int>>(a, p, 5);
  for (auto& i : ans) {
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
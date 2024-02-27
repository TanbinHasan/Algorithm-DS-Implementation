/**
 *    Author  : Ador
 *    Created : 13.08.2020
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> AllNOD(int n) {
  vector<int> nod(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      ++nod[j];
    }
  }
  return nod;
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto nod = AllNOD(n);
  int mx = -1;
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, nod[i]);
  }
  cout << mx;
  return 0;
}

#ifdef Alternative
vector<int> AllNOD(int n) {
  vector<int> nod(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; i * j <= n; ++j) {
      ++nod[i * j];
    }
  }
  return nod;
}
#endif
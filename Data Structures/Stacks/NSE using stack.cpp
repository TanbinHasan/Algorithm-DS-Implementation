/**
 *    author:  T.H666
 *    created: 11.02.2022 03:07:34
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> NSE(vector<int> &ar, int n) {
  vector<int> res(n);
  stack<int> s;
  for (int i = n - 1; i >= 0; --i) {
    if (!s.empty()) {
      while (!s.empty() && ar[i] <= ar[s.top()]) s.pop();
    }
    res[i] = ((s.empty()) ? (-1) : (s.top()));
    s.push(i);
  }
  return res;
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> ar = {1, 2, 3, 4, 3, 2, 5, 1, 6};
  int n = (int)ar.size();
  auto nxt = NSE(ar, n);
  for (int i = 0; i < n; ++i) {
    cout << i << " " << ar[i] << " " << ar[nxt[i]] << '\n';
  }
  return 0;
}
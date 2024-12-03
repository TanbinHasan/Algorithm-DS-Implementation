/**
 *    Author  : Tanbin_Hasan
 *    Created : 27.12.2020
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = 20;
vector<bool> vis(MX);
vector<int> v;
vector<vector<int>> ans;
int n;
vector<int> a;

void rec(void) {
  if ((int)v.size() == n) return void(ans.push_back(v));
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    vis[i] = true;
    v.push_back(a[i]);
    rec();
    vis[i] = false;
    v.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &i : a) {
    cin >> i;
  }
  cout << '\n';
  rec();
  return 0;
}
/**
 *    Author  : Tanbin_Hasan
 *    Created : 27.12.2020
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

vector<int> v;
vector<vector<int>> ans;
vector<int> a;
int n, k;

void rec(int k, int pos) {
  if (!k) return void(ans.push_back(v));
  for (int i = pos; i + k <= n; ++i) {
    v.push_back(a[i]);
    rec(k - 1, i + 1);
    v.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  a.resize(n);
  for (auto& i : a) {
    cin >> i;
  }
  rec(k, 0);
  return 0;
}
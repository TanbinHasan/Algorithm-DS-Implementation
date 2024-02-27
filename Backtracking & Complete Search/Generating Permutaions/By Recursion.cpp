/**
 *    Author  : Tanbin_Hasan
 *    Created : 27.12.2020
 **/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> used(21, false);
vector<int> v;
void GenPer(vector<int> &ar, int n) {
  if ((int)v.size() == n) {
    for (auto &i : v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    used[i] = true;
    v.push_back(ar[i]);
    GenPer(ar, n);
    used[i] = false;
    v.pop_back();
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
  cout << '\n';
  GenPer(ar, n);
  return 0;
}
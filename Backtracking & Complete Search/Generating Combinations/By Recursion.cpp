/**
 *    Author  : Tanbin_Hasan
 *    Created : 27.12.2020
**/
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<vector<int>> comb;
void GenComb(vector<int> &ar, int n, int k, int pos) {
  if (!k) {
    comb.push_back(v);
    return;
  }
  for (int i = pos; i + k <= n; ++i) {
    v.push_back(ar[i]);
    GenComb(ar, n, k - 1, i + 1);
    v.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  GenComb(ar, n, k, 0);
  return 0;
}
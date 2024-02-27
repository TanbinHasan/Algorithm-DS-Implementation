/**
 *    Author  : Tanbin_Hasan
 *    Created : 14.12.2020
**/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void GenPer(vector<int64_t> &ar) {
  do {
    for (auto &i : ar) {
      cout << i << ' ';
    }
    cout << '\n';
  } while (next_permutation(ar.begin(), ar.end()));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  cout << '\n';
  GenPer(ar);
  return 0;
}
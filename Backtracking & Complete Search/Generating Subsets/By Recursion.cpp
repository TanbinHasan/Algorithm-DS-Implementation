/**
 *    Author  : Tanbin_Hasan
 *    Created : 14.12.2020
 **/
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
void SubSets(vector<int> &ar, int pos, int n) {
  if (pos == n) {
    for (auto &i : v) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  }
  SubSets(ar, pos + 1, n);
  v.push_back(ar[pos]);
  SubSets(ar, pos + 1, n);
  v.pop_back();
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
  SubSets(ar, 0, n);
  return 0;
}
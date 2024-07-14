/**
 *    author:  Tanbin_Hasan
 *    created: 01.10.2021 13:49:49
**/
#include <bits/stdc++.h>

using namespace std;

void PathofMinEle(vector<int> &ar, int tar) {
  vector<int> freq(tar + 1, INT_MAX);
  freq[0] = 0;
  vector<int> seq(tar + 1);
  for (auto &i : ar) {
    for (int j = tar; j >= i; --j) {
      if (freq[j - i] != INT_MAX && freq[j - i] + 1 < freq[j]) {
        freq[j] = freq[j - i] + 1;
        seq[j] = i;
      }
    }
  }
  if (!seq[tar]) {
    cout << "No Solution";
    return;
  }
  int cur = tar;
  cout << freq[cur] << '\n';
  while (cur > 0) {
    cout << seq[cur] << ' ';
    cur -= seq[cur];
  }
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, tar;
  cin >> n >> tar;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  PathofMinEle(ar, tar);
  return 0;
}
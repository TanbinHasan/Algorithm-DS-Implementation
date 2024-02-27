/**
 *    Author : Tanbin_Hasan
 *    Created : 31.03.2021 02:17:50
**/
#include <bits/stdc++.h>

using namespace std;

void PathofMinElem(vector<int> &ar, int tar) {
  sort(ar.begin(), ar.end());
  vector<int> freq(tar + 1);
  vector<int> seq(tar + 1);
  for (int i = 1; i <= tar; ++i) {
    freq[i] = INT_MAX - 1;
    for (auto &c : ar) {
      if (i - c < 0) break;
      if (freq[i - c] + 1 < freq[i]) {
        freq[i] = freq[i - c] + 1;
        seq[i] = c;
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
  int n, target;
  cin >> n >> target;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  PathofMinElem(ar, target);
  return 0;
}
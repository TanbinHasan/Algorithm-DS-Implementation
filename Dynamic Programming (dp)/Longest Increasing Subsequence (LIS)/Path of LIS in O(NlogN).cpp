/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 14:10:52
**/
#include <bits/stdc++.h>

#define int long long

using namespace std;

// Explaination: https://www.youtube.com/watch?v=S9oUiVYEq7E
// Implementation: https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/

vector<int> PathOfLIS(vector<int> &ar, int n) {
  vector<int> temp(n);
  vector<int> Prev(n, -1);
  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (ar[i] < ar[temp[0]]) temp[0] = i;
    else if (ar[i] > ar[temp[len - 1]]) {
      Prev[i] = temp[len - 1];
      temp[len++] = i;
    } else {
      int low = 0, high = len - 1, pos = len - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ar[temp[mid]] >= ar[i]) { // Lower Bound
          pos = mid;
          high = mid - 1;
        } else low = mid + 1;
      }
      if (pos) Prev[i] = temp[pos - 1];
      temp[pos] = i;
    }
  }
  vector<int> seq;
  for (int i = temp[len - 1]; i != -1; i = Prev[i]) seq.push_back(ar[i]);
  reverse(seq.begin(), seq.end());
  return seq;
}

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &i : ar) {
    cin >> i;
  }
  auto seq = PathOfLIS(ar, n);
  cout << (int)seq.size() << '\n'; // Length of LIS
  for (auto &i : seq) {
    cout << i << " ";
  }
  return 0;
}
/**
 *    author:  Tanbin_Hasan
 *    created: 02.06.2021 14:10:52
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

// Explaination: https://www.youtube.com/watch?v=S9oUiVYEq7E
// Implementation: https://www.geeksforgeeks.org/construction-of-longest-monotonically-increasing-subsequence-n-log-n/

vector<int> lis_path(vector<int>& a, int n) {
  vector<int> tmp(n);
  vector<int> prv(n, -1);
  int len = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[tmp[0]]) tmp[0] = i;
    else if (a[i] > a[tmp[len - 1]]) {
      prv[i] = tmp[len - 1];
      tmp[len++] = i;
    } else {
      int l = 0, r = len - 1, pos = len - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[tmp[m]] >= a[i]) { // Lower Bound
          pos = m;
          r = m - 1;
        } else l = m + 1;
      }
      if (pos) prv[i] = tmp[pos - 1];
      tmp[pos] = i;
    }
  }
  vector<int> seq;
  for (int i = tmp[len - 1]; i != -1; i = prv[i]) seq.push_back(a[i]);
  reverse(seq.begin(), seq.end());
  return seq;
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
  auto seq = lis_path(ar, n);
  cout << (int)seq.size() << '\n'; // Length of LIS
  for (auto &i : seq) {
    cout << i << " ";
  }
  return 0;
}
/*
// Function to compute the LIS and its path
vector<int> lis_path(vector<int> &a, int n) {
  vector<int> v;         // Stores indices of LIS candidates
  vector<int> prv(n, -1);  // Stores previous indices for path reconstruction

  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(v.begin(), v.end(), a[i], [&](int idx, int val) {
      return a[idx] < val;
    });

    if (it == v.end()) {
      // If 'a[i]' is greater than all elements in 'tmp'
      if (!v.empty()) prv[i] = v.back();
      v.push_back(i);
    } else {
      // Replace the element at the found position
      *it = i;
      if (it != v.begin()) prv[i] = v[it - v.begin() - 1];
    }
  }

  // Reconstruct the LIS
  vector<int> seq;
  for (int i = v.back(); i != -1; i = prv[i]) seq.push_back(a[i]);
  reverse(seq.begin(), seq.end());
  return seq;
}  
*/
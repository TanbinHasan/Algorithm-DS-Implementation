/**
 *    author:  BlackIce666
 *    created: 13.05.2024 21:38:21
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int MX = 10;
vector<bool> col(MX), ld(2 * MX + 1), rd(2 * MX + 1);
vector<vector<int>> store; // all solutions
vector<int> v; // current solution

void rec(int n, int c) {
  if (c == n) { // all columns have been taken
    store.push_back(v);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (col[i] || ld[i + c] || rd[i - c + n - 1]) continue;
    col[i] = ld[i + c] = rd[i - c + n - 1] = true;
    v.push_back(i);
    rec(n, c + 1);
    col[i] = ld[i + c] = rd[i - c + n - 1] = false;
    v.pop_back();
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  rec(n, 0);
  for (auto& v : store) {
    for (auto& i : v) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}

/*
  There are total 2 * n - 1 left diagonal & same number of right diagonal.
  For (i, j) cell,
  it's left diagonal = i + j
  it's right diagonal = i - j + n - 1

  For n = 4, 
  left diagonal:
    0 1 2 3
    1 2 3 4
    2 3 4 5
    3 4 5 6
  right diagonal:
    3 2 1 0
    4 3 2 1
    5 4 3 2
    6 5 4 3
*/
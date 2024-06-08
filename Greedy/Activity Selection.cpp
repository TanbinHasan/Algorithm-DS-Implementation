/**
 *    Author  : Tanbin_Hasan
 *    Created : 22.01.2021
 **/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> FinishTasks(vector<pair<int, int>> &a, int n) {
  sort(a.begin(), a.end());
  vector<pair<int, int>> ans = {{a[0].second, a[0].first}};
  int cur = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i].second > a[cur].first) {
      cur = i;
      ans.emplace_back(a[i].second, a[i].first);
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ar(n);
  for (auto &[END, START] : ar) {
    cin >> START >> END;
  }
  auto TotalTasks = FinishTasks(ar, n);
  cout << (int)TotalTasks.size() << '\n';
  for (auto &[START, END] : TotalTasks) {
    cout << START << ' ' << END << '\n';
  }
  return 0;
}
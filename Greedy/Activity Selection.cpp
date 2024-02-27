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

vector<pair<int, int>> FinishTasks(vector<pair<int, int>> &ar, int n) {
  sort(ar.begin(), ar.end());
  vector<pair<int, int>> ans = {{ar[0].second, ar[0].first}};
  int cur = 0;
  for (int i = 1; i < n; ++i) {
    if (ar[i].second > ar[cur].first) {
      cur = i;
      ans.emplace_back(ar[i].second, ar[i].first);
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
/**
 *    author:  BlackIce666
 *    created: 30.03.2024 17:05:46
 **/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(69);
  l.push_back(420);
  l.push_back(666);
  int k = 69;
  auto it = (l).begin();
  while (it != (l).end() && *it != k) ++it;
  l.insert(it, 425); // insert 425 before 69
  for (auto& i : l) {
    cout << i << " ";
  }
  cout << '\n';
  k = 425;
  it = (l).begin();
  while (it != (l).end() && *it != k) ++it;
  l.erase(it); // erase the element 425
  for (auto& i : l) {
    cout << i << " ";
  }
  cout << '\n';
  reverse(l.begin(), l.end()); // reverse the linked list
  for (auto& i : l) {
    cout << i << " ";
  }
  cout << '\n';
  // rest of the operations are like std::vector
  return 0;
}
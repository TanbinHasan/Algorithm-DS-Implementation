/**
 *    author:  Tanbin_Hasan
 *    created: 22.07.2021 15:00:09
**/
#include <bits/stdc++.h>

using namespace std ;

int main(void) {
  ios::sync_with_stdio(false) ; cin.tie(0) ;
  int nodes , edges ;
  cin >> nodes >> edges ;
  vector<vector<int64_t>> adj(nodes + 1) ;
  for (int i = 0 ; i < edges ; ++i) {
    int x , y ;
    cin >> x >> y ;
    adj[x].push_back(y) ;
    // adj[y].push_back(x) ; // if the graph is undirected
  }
  for (int i = 0 ; i < edges ; ++i) {
    for (auto &j : adj[i]) {
      cout << j << ' ' ;
    }
    cout << '\n' ;
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
vector<int> AStarSearch(vector<vector<pii>>& adj, vector<int>& SLD, int st, int dst) {
  vector<bool> vis(26);
  vector<int> par(26), dis(26);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vis[st] = true;
  par[st] = -1;
  pq.push({SLD[st], st});
  while (!pq.empty()) {
    auto [sld, node] = pq.top();
    pq.pop();
    if (node == dst) {
      vector<int> path;
      int cur = node;
      while (cur != -1) {
        path.push_back(cur);
        cur = par[cur];
      }
      reverse(path.begin(), path.end());
      return path;
    }
    for (auto& [child, cw] : adj[node]) { // traverse all child of node
      if (vis[child]) continue;
      vis[child] = true;
      par[child] = node;
      dis[child] = dis[node] + cw;
      pq.push({SLD[child] + dis[child], child});
    }
  }
  return {}; // if the answer is empty
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nodes, edges;
  cin >> nodes >> edges; // no. of nodes and edges
  vector<vector<pii>> adj(26); // cause max value can be 25('Z' - 'A' == 25)
  while (edges--) {
    string s;
    cin >> s;
    int w, x = s[0] - 'A', y = s[1] - 'A'; // subtract ASCII value of A
    cin >> w; // weight
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }
  vector<int> SLD(26); // since max value can be 25
  for (int i = 0; i < nodes; ++i) {
    char ch;
    cin >> ch;
    int sld;
    cin >> sld;
    SLD[ch - 'A'] = sld;
  }
  char st, dst; // source, destination
  cin >> st >> dst;
  vector<int> ans = AStarSearch(adj, SLD, st - 'A', dst - 'A');
  for (auto& i : ans) {
    cout << (char) (i + 'A') << " "; // add ASCII value here
  }
  cout << '\n';
  return 0;
}
/*
Sample input:
10 14
AB 80
AE 80
AC 75
BF 50
BE 30
CD 70
DG 120
EF 40
EI 150
FH 40
FJ 285
GH 130
HJ 295
IJ 70
A 350
B 280
C 283
D 230
E 290
F 285
G 150
H 295
I 70
J 0
A J
*/
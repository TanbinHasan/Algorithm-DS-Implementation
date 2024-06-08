/**
 *    author:  BlackIce666
 *    created: 10.04.2024 20:39:13
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long int i64;

const int N = 50000; // size of the array
const int M = 50; // max size/bit of each element of array
const int K = 26; // total number of characters
int cval(char ch) { return ch - 'a'; } // Type of characters
int nexts[N * M][K];
int cnt[N * M];
bitset<N * M> endmark;
int node_cnt;

class Trie {
 public:
  Trie() {
    endmark.reset();
    memset(cnt, 0, sizeof cnt);
    memset(nexts, -1, sizeof nexts);
    node_cnt = 0;
  }

  void insert(string s) {
    int cur = 0; // start from the root
    for (auto& i : s) {
      int ch = cval(i);
      if (nexts[cur][ch] == -1)  nexts[cur][ch] = ++node_cnt;
      cur = nexts[cur][ch];
      ++cnt[cur];
    }
    endmark[cur] = 1;
  }

  bool find(string s) {
    int cur = 0;
    for (auto& i : s) {
      int ch = cval(i);
      if (nexts[cur][ch] == -1) return false;
      cur = nexts[cur][ch];
    }
    return endmark[cur];
  }

  void erase(string s) {
    if (!find(s)) return;
    int cur = 0;
    for (auto& i : s) {
      int ch = cval(i);
      cur = nexts[cur][ch];
      --cnt[cur];
    }
    if (!cnt[cur]) endmark[cur] = 0;
  }

  vector<int> frequency(string s) {
    int n = (int)s.size(), cur = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int ch = cval(s[i]);
      if (nexts[cur][ch] == -1) break;
      cur = nexts[cur][ch];
      v[i] = cnt[cur];
    }
    return v;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Trie trie;
  trie.insert("apple");
  trie.insert("apple");
  trie.insert("app");
  trie.insert("banana");
  trie.insert("banana");
  trie.insert("banana");
  trie.insert("cat");
  trie.insert("cat");
  trie.insert("cat");
  trie.insert("cat");
  trie.insert("dog");
  trie.erase("cat");
  trie.erase("cat");
  trie.insert("cat");
  trie.insert("cat");
  trie.insert("cat");
  trie.insert("cat");
  trie.erase("banana");
  // trie.erase("banana");
  trie.erase("banana");
  cout << "apple: " << trie.find("apple") << '\n';
  for (auto& i : trie.frequency("apple")) {
    cout << i << " ";
  }
  cout << '\n';

  cout << "banana: " << trie.find("banana") << '\n';
  for (auto& i : trie.frequency("banana")) {
    cout << i << " ";
  }
  cout << '\n';

  cout << "cat: " << trie.find("cat") << '\n';
  for (auto& i : trie.frequency("cat")) {
    cout << i << " ";
  }
  cout << '\n';

  cout << "dog: " << trie.find("dog") << '\n';
  for (auto& i : trie.frequency("dog")) {
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
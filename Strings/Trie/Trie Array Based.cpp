/**
 *    author:  BlackIce666
 *    created: 10.04.2024 20:39:13
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long int i64;

const int N = 50000;  // size of the array
const int M = 50;     // max size/bit of each element of array
const int K = 26;     // total number of characters

int nxt[N * M][K];
int cnt[N * M];
bool endmark[N * M];

class Trie {
  int node_at;
  
  int index(char ch) {  // type of chars
    if (islower(ch)) return ch - 'a';
    if (isupper(ch)) return ch - 'A';
    if (isdigit(ch)) return ch - '0';
    throw invalid_argument("Invalid");
  }

 public:
  Trie() : node_at(0) {
    memset(cnt, 0, sizeof cnt);
    memset(nxt, -1, sizeof nxt);
    memset(endmark, false, sizeof endmark);
  }

  void insert(string s) {
    int at = 0;  // start from the root
    for (auto& i : s) {
      int ch = index(i);
      if (nxt[at][ch] == -1) nxt[at][ch] = ++node_at;
      at = nxt[at][ch];
      ++cnt[at];
    }
    endmark[at] = 1;
  }

  bool find(string s) {
    int at = 0;
    for (auto& i : s) {
      int ch = index(i);
      if (nxt[at][ch] == -1) return false;
      at = nxt[at][ch];
    }
    return endmark[at];
  }

  void erase(string s) {
    if (!find(s)) return;
    int at = 0;
    for (auto& i : s) {
      int ch = index(i);
      at = nxt[at][ch];
      --cnt[at];
    }
    if (!cnt[at]) endmark[at] = 0;
  }

  vector<int> frequency(string s) {
    int at = 0, n = (int)s.size();
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int ch = index(s[i]);
      if (nxt[at][ch] == -1) break;
      at = nxt[at][ch];
      v[i] = cnt[at];
    }
    return v;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Trie trie;
  trie.insert("appl#");
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
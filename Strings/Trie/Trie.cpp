/**
 *    author:  BlackIce666
 *    created: 04.04.2024 23:03:19
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long int i64;

const int MX = 10; // total number of characters

class Node {
  public:
  bool endmark;
  int cnt;
  Node* nxt[MX] = {};
  Node() : endmark(false), cnt(0) {}
};

class Trie {
  void clear(Node* at) {
    if (!at) return;
    for (auto i : at->nxt) clear(i);
    delete at;
  }

  int index(char ch) { 
    if (islower(ch)) return ch - 'a';
    if (isupper(ch)) return ch - 'A';
    if (isdigit(ch)) return ch - '0';
  }

  Node* root;

 public:
  Trie() { root = new Node(); }
  ~Trie() { clear(root); }

  void insert(string s) {
    Node* at = root;
    for (auto& i : s) {
      int ch = index(i);
      if (!at->nxt[ch]) at->nxt[ch] = new Node();
      at = at->nxt[ch];
      ++at->cnt;
    }
    at->endmark = true;
  }

  bool find(string s) {
    Node* at = root;
    for (auto& i : s) {
      int ch = index(i);
      if (!at->nxt[ch]) return false; // if null pointer
      at = at->nxt[ch];
    }
    return at->endmark;
  }

  void erase(string s) {
    if (!find(s)) return;
    Node* at = root;
    for (auto& i : s) {
      int ch = index(i);
      at = at->nxt[ch];
      --at->cnt;
    }
    if (!at->cnt) at->endmark = false;
  }

  vector<int> frequency(string s) {
    Node* at = root;
    int n = (int)s.size();
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int ch = index(s[i]);
      if (!at->nxt[ch]) break;
      at = at->nxt[ch];
      v[i] = at->cnt;
    }
    return v;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Trie t;
  t.insert("apple");
  t.insert("apple");
  t.insert("app");
  t.insert("banana");
  t.insert("banana");
  t.insert("banana");
  t.insert("cat");
  t.insert("cat");
  t.insert("cat");
  t.insert("cat");
  t.insert("dog");
  t.erase("cat");
  t.erase("cat");
  t.insert("cat");
  t.insert("cat");
  t.insert("cat");
  t.insert("cat");
  t.erase("banana");
  t.erase("banana");
  t.erase("banana");
  cout << "apple: " << t.find("apple") << '\n';
  for (auto& i : t.frequency("apple")) {
    cout << i << " ";
  }
  cout << '\n';

  cout << "banana: " << t.find("banana") << '\n';
  for (auto& i : t.frequency("banana")) {
    cout << i << " ";
  }
  cout << '\n';

  cout << "cat: " << t.find("cat") << '\n';
  for (auto& i : t.frequency("cat")) {
    cout << i << " ";
  }
  cout << '\n';

  cout << "dog: " << t.find("dog") << '\n';
  for (auto& i : t.frequency("dog")) {
    cout << i << " ";
  }
  cout << '\n';
  return 0;
}
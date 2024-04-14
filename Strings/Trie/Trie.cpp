/**
 *    author:  BlackIce666
 *    created: 04.04.2024 23:03:19
 **/
#include <bits/stdc++.h>

#define int long long

using namespace std;

class Trie {
  class node {
   public:
    bool endmark;
    int cnt;
    node* next[26] = {};
    node() {
      endmark = false;
      cnt = 0;
    }
  };
  node* head;
  void destroy(node* cur) {
    if (!cur) return;
    for (auto nxt : cur->next) destroy(nxt);
    delete (cur);
  }
 public:
  Trie() { head = new node(); }
  ~Trie() { destroy(head); }

  int32_t cval(char ch) { return ch - 'a'; }

  void insert(string s) {
    node* cur = head;
    for (auto& i : s) {
      int ch = cval(i);
      if (!cur->next[ch]) cur->next[ch] = new node();
      cur = cur->next[ch];
      ++cur->cnt;
    }
    cur->endmark = true;
  }

  bool find(string s) {
    node* cur = head;
    for (auto& i : s) {
      int ch = cval(i);
      if (!cur->next[ch]) return false; // if null pointer
      cur = cur->next[ch];
    }
    return cur->endmark;
  }

  void erase(string s) {
    if (!find(s)) return;
    node* cur = head;
    for (auto& i : s) {
      int ch = cval(i);
      cur = cur->next[ch];
      --cur->cnt;
    }
    if (!cur->cnt) cur->endmark = false;
  }

  vector<int> frequency(string s) {
    node* cur = head;
    int n = (int)s.size();
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      int ch = cval(s[i]);
      if (!cur->next[ch]) break;
      cur = cur->next[ch];
      v[i] = cur->cnt;
    }
    return v;
  }
};

int32_t main(void) {
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
  trie.erase("banana");
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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Trie {
 public:
  gp_hash_table<char, Trie> child;
  bool ok = false;
  int cnt = 0;
  void insert(const string& s, int pos = 0) {
    if (pos == (int)s.size()) {
      ok = true;
      ++cnt;
      return;
    }
    child[s[pos]].insert(s, pos + 1);
  }
  int freq(const string& s, int pos = 0) {
    if (pos == (int)s.size()) return cnt;
    if (child.find(s[pos]) == (child).end()) return 0;
    return child[s[pos]].freq(s, pos + 1);
  }
  void erase(const string& s, int pos = 0) {
    if (pos == (int)s.size()) {
      if (--cnt == 0) ok = false;
      return;
    }
    if (child.find(s[pos]) == (child).end()) return;
    child[s[pos]].erase(s, pos + 1);
    if (child[s[pos]].child.empty() && !child[s[pos]].ok) child.erase(s[pos]);
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Trie trie;
  trie.insert("apple");
  trie.insert("apple");
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
  cout << "Frequency of \"apple\": " << trie.freq("apple") << '\n';
  cout << "Frequency of \"banana\": " << trie.freq("banana") << '\n';
  cout << "Frequency of \"cat\": " << trie.freq("cat") << '\n';
  cout << "Frequency of \"dog\": " << trie.freq("dog") << '\n';
  return 0;
}
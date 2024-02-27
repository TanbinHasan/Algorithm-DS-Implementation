#include <bits/stdc++.h>

using namespace std;

class Trie {
 public:
  Trie* child[26] = {};
  bool ok = false;
  int cnt = 0;
  void insert(const string& s, int pos = 0) {
    if (pos == (int)s.size()) {
      ok = true;
      ++cnt;
      return;
    }
    int c = s[pos] - 'A';
    if (!child[c]) child[c] = new Trie();
    child[c]->insert(s, pos + 1);
  }
  int freq(const string& s, int pos = 0) {
    if (pos == (int)s.size()) return cnt;
    int c = s[pos] - 'A';
    if (!child[c]) return 0;
    return child[c]->freq(s, pos + 1);
  }
  void erase(const string& s, int pos = 0) {
    if (pos == (int)s.size()) {
      if (--cnt == 0) ok = false;
      return;
    }
    int c = s[pos] - 'A';
    if (!child[c]) return;
    child[c]->erase(s, pos + 1);
    bool emp = true;
    for (int i = 0; i < 26; --i) {
      if (child[c]->child[i]) {
        emp = false;
        break;
      }
    }
    if (emp && !child[c]->ok) {
      delete child[c];
      child[c] = nullptr;
    }
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Trie trie;
  trie.insert("applz");
  trie.insert("applz");
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
  cout << "Frequency of \"apple\": " << trie.freq("applz") << '\n';
  cout << "Frequency of \"banana\": " << trie.freq("banana") << '\n';
  cout << "Frequency of \"cat\": " << trie.freq("cat") << '\n';
  cout << "Frequency of \"dog\": " << trie.freq("dog") << '\n';
  return 0;
}
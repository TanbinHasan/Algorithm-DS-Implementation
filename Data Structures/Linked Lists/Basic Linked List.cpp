/**
 *    author:  BlackIce666
 *    created: 05.01.2024 18:24:09
 **/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

class linked_list {
  class node {
   public:
    int roll;
    node* next;
    node(int roll) {
      this->roll = roll;
      this->next = nullptr;
    }
  };
  node* root;
 public:
  linked_list() { root = nullptr; }
  void append(int roll) {
    if (root == nullptr) {  // if the list is empty
      root = new node(roll);
      return;
    }
    node* cur = root;
    while (cur->next != nullptr) cur = cur->next;
    node* newnode = new node(roll);
    cur->next = newnode;  // link the last node with newnode
  }
  void delete_node(int roll) {
    node* cur = root;
    node* prv = nullptr;
    bool found = false;
    while (cur != nullptr && !found) {
      if (cur->roll == roll) found = true;
      else {
        prv = cur;
        cur = cur->next;
      }
    }
    if (!found) {
      cout << "Node with roll " << roll << " not found in the list.\n";
      return;
    }
    if (cur == root) {
      node* temp = root;
      root = root->next;
      delete (temp);
    } else {
      prv->next = cur->next;
      delete (cur);
    }
  }
  void print() {
    node* cur = root;
    while (cur != nullptr) {
      cout << cur->roll << " ";
      cur = cur->next;
    }
  }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  linked_list l;
  l.append(1);
  l.append(2);
  l.append(69);
  l.append(420);
  l.append(666);
  l.print();
  return 0;
}
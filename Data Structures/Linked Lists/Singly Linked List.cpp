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
  node* head;
 public:
  linked_list() { head = nullptr; }

  void push(int roll) {
    if (head == nullptr) {  // if the list is empty
      head = new node(roll);
      return;
    }
    node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = new node(roll);  // link the last node with newnode
  }

  void erase(int roll) {
    node* cur = head;
    node* prv = nullptr;
    bool found;
    while (cur != nullptr && !found) {
      if (cur->roll == roll) found = true;
      else {
        prv = cur;
        cur = cur->next;
      }
    }
    if (!found) return;
    if (cur == head) {
      node* temp = head;
      head = head->next;
      delete (temp);
    } else {
      prv->next = cur->next;
      delete (cur);
    }
  }

  void insert(int after, int roll) {
    node* cur = head;
    bool found;
    while (cur != nullptr && !found) {
      if (cur->roll == after) found = true;
      else cur = cur->next;
    }
    if (!found) return;
    node* new_node = new node(roll);
    new_node->next = cur->next;
    cur->next = new_node;
  }
  
  void print() {
    node* cur = head;
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
  l.push(1);
  l.push(2);
  l.push(69);
  l.push(420);
  l.erase(421);
  l.push(666);
  l.insert(69, 425);
  l.print();
  return 0;
}
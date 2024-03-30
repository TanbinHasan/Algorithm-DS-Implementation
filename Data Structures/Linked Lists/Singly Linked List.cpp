/**
 *    author:  BlackIce666
 *    created: 05.01.2024 18:24:09
 **/
#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

template <typename T>
class linked_list {
  class node {
   public:
    T data;
    node* next;
    node(const T& data) {
      this->data = data;
      this->next = nullptr;
    }
  };
  node* head;
 public:
  linked_list() { head = nullptr; }

  void push(const T& data) {
    if (head == nullptr) {  // if the list is empty
      head = new node(data);
      return;
    }
    node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = new node(data);  // link the last node with newnode
  }

  void erase(const T& data) {
    node* cur = head;
    node* prv = nullptr;
    bool found;
    while (cur != nullptr && !found) {
      if (cur->data == data) found = true;
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

  void insert(const T& after, const T& data) {
    node* cur = head;
    bool found;
    while (cur != nullptr && !found) {
      if (cur->data == after) found = true;
      else cur = cur->next;
    }
    if (!found) return;
    node* new_node = new node(data);
    new_node->next = cur->next;
    cur->next = new_node;
  }
  
  void print() {
    node* cur = head;
    while (cur != nullptr) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << '\n';
  }
};

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  linked_list<int> l;
  l.push(1);
  l.push(2);
  l.push(69);
  l.push(420);
  l.erase(421);
  l.push(666);
  l.insert(69, 425);
  l.print();
  linked_list<string> ls;
  ls.push("Rumu");
  ls.push("Ador");
  ls.push("Habib");
  ls.erase("Habiba");
  ls.push("Efti");
  ls.insert("Habib", "baal");
  ls.print();
  return 0;
}
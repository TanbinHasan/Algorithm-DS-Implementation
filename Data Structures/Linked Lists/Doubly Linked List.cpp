/**
 *    author:  BlackIce666
 *    created: 30.03.2024 17:05:46
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
    node *next, *prev;
    node(const T& data) {
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
    }
  };
  node *head, *tail;

 public:
  linked_list() { head = tail = nullptr; }

  void push(const T& data) {
    node* new_node = new node(data);
    if (head == nullptr) {  // if the list is empty
      head = tail = new_node;
      return;
    }
    tail->next = new_node;  // link the last node with new node
    new_node->prev = tail;  // link new node back to the last node
    tail = new_node;        // update the tail to the new last node
  }

  void erase(const T& data) {
    node* cur = head;
    bool found;
    while (cur != nullptr && !found) {
      if (cur->data == data) found = true;
      else cur = cur->next;
    }
    if (!found) return;
    if (cur == head && cur == tail) {  // only node
      head = tail = nullptr;
    } else if (cur == head) {       // erasing head
      head = cur->next;             // move head
      head->prev = nullptr;         // update prev of new head
    } else if (cur == tail) {       // erasing tail
      tail = cur->prev;             // move tail
      tail->next = nullptr;         // update next of new tail
    } else {                        // erasing from middle
      cur->prev->next = cur->next;  // link prev node to the next node
      cur->next->prev = cur->prev;  // link next node to the prev node
    }
    delete (cur);
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
    new_node->next = cur->next;  // Link the new node to the next node
    new_node->prev = cur;        // Link the new node to the current node
    if (cur == tail) tail = new_node;  // Update the tail pointer
    else cur->next->prev = new_node;  // Update the previous pointer of the next node
    cur->next = new_node;          // Update the next pointer of the current node
  }

  void print() {
    node* cur = head;
    while (cur != nullptr) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << '\n';
  }
  void reverseprint() {
    node* cur = tail;
    while (cur != nullptr) {
      cout << cur->data << " ";
      cur = cur->prev;
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
  l.reverseprint();
  linked_list<string> ls;
  ls.push("Rumu");
  ls.push("Ador");
  ls.push("Habib");
  ls.erase("Habiba");
  ls.push("Efti");
  ls.insert("Habib", "baal");
  ls.print();
  ls.reverseprint();
  return 0;
}
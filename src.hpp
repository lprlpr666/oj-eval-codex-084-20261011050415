//
// Created by wzj on 2021/12/3.
// Modified by Yifei Ma on 2023/10/25.
// Implemented LinkedHashMap functionality.
//

#ifndef FINAL_SRC_HPP
#define FINAL_SRC_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

// Node of the linked hash map. Used in both the hash bucket (singly linked) and
// the insertion‑order doubly linked list.
struct Node {
  Node* next = nullptr;      // next in hash bucket list
  Node* timePre = nullptr;   // previous in insertion order list
  Node* timeNext = nullptr;  // next in insertion order list
  int key = 0;
  string value;
};

struct Data {
  int key;
  string value;
};

// Forward declarations for traversal functions.
vector<Data> traverseByTime(const struct LinkedHashMap& obj);
vector<Data> traverseByIndex(const struct LinkedHashMap& obj);

struct LinkedHashMap {
  int len = 0;            // number of buckets
  Node** array = nullptr; // array of bucket heads (singly linked lists)
  Node* beg = nullptr;    // dummy head of doubly linked insertion‑order list
  Node* cur = nullptr;    // tail of the doubly linked list
  // Function pointer selecting traversal method.
  vector<Data> (*forEachMethod)(const LinkedHashMap&);

  // Initialise the data structure.
  void init(int len_, bool forEachByTime) {
    len = len_;
    beg = new Node();          // sentinel node, does not hold real data
    cur = beg;                 // tail initially points to sentinel
    array = new Node*[len];
    for (int i = 0; i < len; ++i) array[i] = nullptr;
    forEachMethod = forEachByTime ? traverseByTime : traverseByIndex;
  }

  // Release all allocated memory.
  void clearMemory() {
    Node* p = beg->timeNext;
    while (p) {
      Node* nxt = p->timeNext;
      delete p;
      p = nxt;
    }
    delete beg;
    delete[] array;
    beg = cur = nullptr;
    array = nullptr;
    len = 0;
  }

  // Insert a node at the head of its bucket and at the tail of the insertion‑order list.
  void insert(int key, string value) {
    Node* node = new Node();
    node->key = key;
    node->value = std::move(value);
    // Bucket list (head insertion).
    node->next = array[key];
    array[key] = node;
    // Append to doubly linked list.
    cur->timeNext = node;
    node->timePre = cur;
    node->timeNext = nullptr;
    cur = node;
  }

  // Remove all nodes in bucket `key` whose value matches `value`.
  void remove(int key, string value) {
    Node* prev = nullptr;
    Node* curNode = array[key];
    while (curNode) {
      if (curNode->value == value) {
        // Unlink from bucket list.
        if (prev) prev->next = curNode->next; else array[key] = curNode->next;
        // Unlink from doubly linked list.
        Node* pre = curNode->timePre;
        Node* nxt = curNode->timeNext;
        if (pre) pre->timeNext = nxt;
        if (nxt) nxt->timePre = pre;
        if (this->cur == curNode) this->cur = pre;
        Node* toDelete = curNode;
        curNode = curNode->next;
        delete toDelete;
        // prev unchanged
      } else {
        prev = curNode;
        curNode = curNode->next;
      }
    }
  }

  // Return all values in bucket `key` from head to tail.
  vector<string> ask(int key) const {
    vector<string> res;
    for (Node* p = array[key]; p; p = p->next) {
      res.push_back(p->value);
    }
    return res;
  }

  // Traverse all nodes using the selected method.
  vector<Data> forEach() const { return forEachMethod(*this); }
};

// Traversal implementations.
vector<Data> traverseByTime(const LinkedHashMap& obj) {
  vector<Data> res;
  for (Node* p = obj.beg->timeNext; p; p = p->timeNext) {
    res.push_back({p->key, p->value});
  }
  return res;
}

vector<Data> traverseByIndex(const LinkedHashMap& obj) {
  vector<Data> res;
  for (int i = 0; i < obj.len; ++i) {
    for (Node* p = obj.array[i]; p; p = p->next) {
      res.push_back({p->key, p->value});
    }
  }
  return res;
}

#endif // FINAL_SRC_HPP


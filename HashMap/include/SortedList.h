//
// Created by Nico Roble on 2019-10-07.
//

#ifndef HASHMAP_SORTEDLIST_H
#define HASHMAP_SORTEDLIST_H

#include <vector>

using namespace std;

class Node {

 private:
  int data;
  Node *next;
 public:

  int getData() const {
    return data;
  }
  void setData(int data) {
    Node::data = data;
  }

  Node *getNext() const {
    return Node::next;
  }
  void setNext(Node *next) {
    Node::next = next;
  }

  Node(int data) {
    Node::data = data;
    Node::next = nullptr;
  }

};

class SortedList {

 private:
  Node *head;
  Node *tail;
  int count;

  void add_first(int data) {
    Node *new_node = new Node(data);
    new_node->setNext(nullptr);

    if(SortedList::head == nullptr) {
      SortedList::head = new_node;
      SortedList::tail = SortedList::head;
    }
    else {
      new_node->setNext(SortedList::head);
      SortedList::head = new_node;
    }
    ++SortedList::count;

  }
  void add_last(int data) {
    Node *new_node = new Node(data);
    new_node->setNext(nullptr);

    if(SortedList::head == nullptr) {
      SortedList::tail = new_node;
      SortedList::head = SortedList::tail;
    }

    else {
      SortedList::tail->setNext(new_node);
      SortedList::tail = new_node;
    }
    ++SortedList::count;


  }

 public:

  Node *getHead() {
    return SortedList::head;
  }

  Node *getTail() {
    return SortedList::tail;
  }

  int getCount() {
    return SortedList::count;
  }

  void insert(int data) {

    if(SortedList::head == nullptr) {
      add_first(data);
      return;
    }
    if(data < SortedList::head->getData()) {
      add_first(data);
      return;
    }
    if(data > SortedList::tail->getData()) {
      add_last(data);
      return;
    }

    Node *current = SortedList::head;
    Node *next = current->getNext();

    while(next != nullptr) {
      if(next->getData() >= data) {
        // insert
        Node *new_node = new Node(data);
        new_node->setNext(next);
        current->setNext(new_node);
        break;

      }
      // move
      current = current->getNext();
      next = next->getNext();
    }

    ++SortedList::count;
  }

  void remove_first() {
    if(SortedList::head == nullptr) {
      throw "The List is empty!\n";
    }

    Node *temp = SortedList::head;

    if(SortedList::head->getNext() == nullptr) {
      SortedList::head = nullptr;
      SortedList::tail = SortedList::head;
    }
    else {
      SortedList::head = SortedList::head->getNext();
    }
    int tmp_data = temp->getData();
    delete temp;
    --SortedList::count;
    cout << "Deleted " + to_string(tmp_data) + " \n";

  }

  void remove_last() {
    if(SortedList::head == nullptr) {
      throw "The list is empty!\n";
    }
    if(SortedList::head == SortedList::tail) {
      SortedList::remove_first();
    }
    Node *current = SortedList::head;
    Node *previous = nullptr;

    while(current != SortedList::tail) {
      previous = current;
      current = current->getNext();
    }

    SortedList::tail = previous;
    previous->setNext(nullptr);
    int current_data = current->getData();
    delete current;
    --SortedList::count;
    cout << "Deleted " + to_string(current_data) + " \n";
  }

  void remove(int data) {
    if(SortedList::head->getData() == data) {
      return SortedList::remove_first();
    }

    if(SortedList::tail->getData() == data) {
      return SortedList::remove_last();
    }

    Node *current = SortedList::head->getNext();
    Node *previous = SortedList::head;
    while(current != SortedList::tail) {
      if(current->getData() == data) {
        previous->setNext(current->getNext());
        int current_data = current->getData();
        delete current;
        --SortedList::count;
        cout << "Deleted " + to_string(current_data) + " \n";
        return;
      }
      else {
        previous = current;
        current = current->getNext();
      }
    }
    cout << "Element does not exist in list\n";
  }

  int search(int data) {
    if(SortedList::head ==nullptr && SortedList::tail ==nullptr) {
      return -1;
    }

    if(SortedList::head->getData() == data) {
      return 1;
    }

    if(SortedList::tail->getData() == data) {
      return 1;
    }

    Node *current = SortedList::head;
    int step_count = 1;
    //search
    while(current != SortedList::tail) {
      ++step_count;
      if(current->getData() == data) {
        return step_count;
      }
      else {
        current = current->getNext();
      }
    }
    //no matches
    return -1;
  }

  vector<int> to_vector() {
    vector<int> result;

    Node *current = SortedList::head;

    while(current != nullptr) {
      result.push_back(current->getData());
      current = current->getNext();
    }
    return result;
  }

  void print() {
    Node *current = SortedList::head;
    cout << "Printing list:\n";

    if(SortedList::count < 1) {
      cout << "The list is empty!\n";
      return;
    }

    while(current !=nullptr) {
      cout << to_string(current->getData()) + ", ";
      current = current->getNext();
    }
    cout << "\n";
  }

  ~SortedList() {
    Node *current = SortedList::head;
    while(current !=nullptr) {
      Node *next = current->getNext();
      Node *tmp = current;
      delete tmp;
      current = next;
    }
  }
};

#endif //HASHMAP_SORTEDLIST_H

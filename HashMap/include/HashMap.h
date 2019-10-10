//
// Created by Nico Roble on 2019-10-07.
//

#ifndef HASHMAP_HASHMAP_H
#define HASHMAP_HASHMAP_H

#include <SortedList.h>

using namespace std;

class HashMap {
 private:
  SortedList* index;
  int buckets;

  int hash(int data) {
    return data % HashMap::buckets;
  }

 public:

  void insert(int data) {
    int bucket = HashMap::hash(data);
    HashMap::index[bucket].insert(data);
  }

  int search(int data) {
    int bucket = HashMap::hash(data);
    return HashMap::index[bucket].search(data);
  }

  HashMap(int buckets) {
    HashMap::index = new SortedList[buckets];
    HashMap::buckets = buckets;
  }
  ~HashMap() {
    delete []HashMap::index;
  }
};

#endif //HASHMAP_HASHMAP_H

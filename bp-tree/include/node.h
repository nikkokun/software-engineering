//
// Created by Nico Roble on 2020-01-18.
//

#ifndef BP_TREE_NODE_H
#define BP_TREE_NODE_H

#include <block.h>
#include <iostream>
#include <vector>

namespace bptree {

const int NODE_SIZE = 4;

class Node {

 private:
  bool is_leaf = true;
  int key_count = 0;
  Block blocks[NODE_SIZE];
  Node* neighbor = nullptr;
  Node* parent = nullptr;

 public:
  bool get_is_leaf();
  bool set_is_leaf(bool is_leaf);

  int get_key_count();
  int set_key_count(int count);

  std::vector<int> get_keys();

  Node* get_parent();
  Node* set_parent(Node* parent);

  Node* get_neighbor();
  Node* set_neighbor(Node* neighbor);

  int search(int key);
  Node* search_block(int key);
  void shift_right(int index);
  int insert_internal(int key, Node* leaf, Node* new_leaf);
  int insert_leaf(int key);
  std::vector<Block> split();
  Node* get_left_most();
  void print_node();
  void print_neighbor();

  ~Node();

};

}

#endif //BP_TREE_NODE_H

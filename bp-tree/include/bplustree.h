//
// Created by Nico Roble on 2020-01-18.
//

#ifndef BP_TREE_BPLUSTREE_H
#define BP_TREE_BPLUSTREE_H

#include <node.h>
#include <block.h>
#include <tuple>
#include <iostream>

namespace bptree {

class BPlusTree {
 private:
  Node* root;
  bool is_empty = true;
  Node* get_root();
  Node* set_root(Node* node);
  int insert_in_parent(Node* node, Node* new_node, int key);
  Node* search_leaf(int key);

 public:
  int insert(int key);
  int search(int key);
  void print_tree();
};



}

#endif //BP_TREE_BPLUSTREE_H

//
// Created by Nico Roble on 2020-01-18.
//

#ifndef BP_TREE_BLOCK_H
#define BP_TREE_BLOCK_H

namespace bptree {

class Node;

class Block {
 private:
  int key;
  int value;
  Node* left;
  Node* right;

 public:
  int get_key();
  int set_key(int key);

  int get_value();
  int set_value(int value);

  Node* get_left();
  Node* set_left(Node* node);

  Node* get_right();
  Node* set_right(Node* node);

  Block();
  ~Block();
};

}

#endif //BP_TREE_BLOCK_H

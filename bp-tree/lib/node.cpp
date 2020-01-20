//
// Created by Nico Roble on 2020-01-17.
//
#include <iostream>
#include <node.h>
#include <block.h>

using namespace bptree;

bool Node::get_is_leaf() {
  return Node::is_leaf;
}

bool Node::set_is_leaf(bool is_leaf) {
  Node::is_leaf = is_leaf;
  return Node::is_leaf;
}

Node* Node::get_parent() {
  return Node::parent;
}

Node* Node::set_parent(bptree::Node *parent) {
  Node::parent = parent;
  return Node::parent;
}

int Node::get_key_count() {
  return Node::key_count;
}

int Node::set_key_count(int count) {
  Node::key_count = count;
  return Node::key_count;
}

Node* Node::get_neighbor() {
  return Node::neighbor;
}

Node* Node::set_neighbor(bptree::Node *neighbor) {
  Node::neighbor = neighbor;
  return Node::neighbor;
}

int Node::search(int key) {
  for (Block block : Node::blocks) {
    if(key == block.get_key()) {
      return block.get_key();
    }
  }
  return -1;
}

Node* Node::search_block(int key) {

  int current = 0;
  int previous = -1;

  while(current < NODE_SIZE) {
    if(key < Node::blocks[current].get_key()) {
      return Node::blocks[current].get_left();
    }
    else if(Node::blocks[current].get_key() == -1) {
      return Node::blocks[previous].get_right();
    }
    previous = current;
    ++current;
  }
  return Node::blocks[NODE_SIZE - 1].get_right();
}

void Node::shift_right(int index) {
  int current_index = index;
  int prev = -1;
  int current = -1;
  while(current_index < NODE_SIZE) {
    current = Node::blocks[current_index].get_key();
    Node::blocks[current_index].set_key(prev);
    prev = current;
    ++current_index;
  }
}

int Node::insert_internal(int key, bptree::Node *leaf, bptree::Node *new_leaf) {
  int current = 0;

  while(current < NODE_SIZE) {
    if(key <= Node::blocks[current].get_key() || Node::blocks[current].get_key() == -1) {
      Node::shift_right(current);
      Node::blocks[current].set_key(key);
      Node::blocks[current].set_left(leaf);
      Node::blocks[current].set_right(new_leaf);
      leaf->set_parent(this);
      new_leaf->set_parent(this);
      ++Node::key_count;
      return Node::blocks[current].get_key();
    }
    else {
      ++current;
    }
  }
  return -1;
}

int Node::insert_leaf(int key) {
  int current = 0;

  while(current < NODE_SIZE) {
    if(key <= Node::blocks[current].get_key() || Node::blocks[current].get_key() == -1) {
      Node::shift_right(current);
      Node::blocks[current].set_key(key);
      ++Node::key_count;
      return Node::blocks[current].get_key();
    }
    else {
      ++current;
    }
  }
  return -1;
}

std::vector<Block> Node::split() {
  std::vector<Block> result;
  for (int i = NODE_SIZE / 2; i < NODE_SIZE; ++i) {
    result.push_back(Node::blocks[i]);
    Node::blocks[i].set_key(-1);
    --Node::key_count;
  }
  return result;
}

void Node::print_node() {
  for(Block block : Node::blocks) {
    if(block.get_key() != -1) {
      std::cout << block.get_key() << ',';
    }
  }
}

void Node::print_neighbor() {
  std::cout << '[';
  print_node();
  std::cout << ']';
  if(neighbor !=nullptr) {
    neighbor->print_neighbor();
  }
  else {
    return;
  }
}

Node* Node::get_left_most() {
  return Node::blocks[0].get_left();
}

Node::~Node() {
  //set siblings
  for(Block block : Node::blocks) {
    block.set_left(nullptr);
    block.set_right(nullptr);
    block.set_key(-1);
  }
  Node::neighbor = nullptr;
  Node::parent = nullptr;
}
//
// Created by Nico Roble on 2020-01-20.
//
#include <bplustree.h>

using namespace bptree;

Node* BPlusTree::get_root() {
  return BPlusTree::root;
}

Node* BPlusTree::set_root(Node* node) {
  BPlusTree::root = node;
  return BPlusTree::root;
}

int BPlusTree::insert_in_parent(bptree::Node* node, bptree::Node *new_node, int key) {
  new_node->set_neighbor(node->get_neighbor());
  node->set_neighbor(new_node);
  if(BPlusTree::get_root() == node) {
    auto new_parent_node = new Node();
    new_parent_node->set_is_leaf(false);
    int return_val = new_parent_node->insert_internal(key, node, new_node);
    BPlusTree::set_root(new_parent_node);
    return return_val;
  }

  Node* parent = node->get_parent();

  if(parent->get_key_count() < NODE_SIZE -1) {
    return parent->insert_internal(key, node, new_node);
  }
  else {
    parent->insert_internal(key, node, new_node);
    auto tmp_node = parent->split();
    auto new_parent_node = new Node();
    new_parent_node->set_is_leaf(false);
    int new_key = tmp_node[0].get_key();

    for (int i = 1; i < tmp_node.size(); ++i) {
      new_parent_node->insert_internal(tmp_node[i].get_key(), tmp_node[i].get_left(), tmp_node[i].get_right());
    }

    return insert_in_parent(parent, new_parent_node, new_key);
  }
}

int BPlusTree::insert(int key) {

  Node* leaf_node = nullptr;

  if(BPlusTree::is_empty){
    leaf_node = BPlusTree::set_root(new Node());
    BPlusTree::is_empty = false;
  }
  else {
    leaf_node = search_leaf(key);
  }

  // if L has less than n - 1 key values
  if(leaf_node->get_key_count() < NODE_SIZE - 1) {
    return leaf_node->insert_leaf(key);
  }
  else {
    leaf_node->insert_leaf(key);
    auto tmp_node = leaf_node->split();
    auto new_leaf_node = new Node();
    int new_key = tmp_node[0].get_key();

    for (Block block : tmp_node) {
      new_leaf_node->insert_leaf(block.get_key());
    }
    return insert_in_parent(leaf_node, new_leaf_node, new_key);
  }
}

int BPlusTree::search(int key) {
  Node* current_node = BPlusTree::get_root();
  while(!current_node->get_is_leaf()) {
    current_node = current_node->search_block(key);
  }
  return current_node->search(key);
}

Node* BPlusTree::search_leaf(int key) {
  Node* current_node = BPlusTree::get_root();
  Node* parent_node = nullptr;

  while(!current_node->get_is_leaf()) {
    parent_node = current_node;
    current_node = parent_node->search_block(key);
  }
  return current_node;
}

void BPlusTree::print_tree() {
  Node* current_node = BPlusTree::get_root();
  while(current_node !=nullptr) {
    if(current_node->get_neighbor()) {
      current_node->print_neighbor();
    }
    else {
      current_node->print_node();
    }
    std::cout << '\n';
    current_node = current_node->get_left_most();
  }
}

BPlusTree::~BPlusTree() {
  Node* current_node = BPlusTree::get_root();
  Node * next_node = current_node->get_left_most();
  while(next_node != nullptr) {
    current_node = current_node->get_left_most();
    next_node = current_node->get_left_most();
  }
  Node* parent_node = current_node->get_parent();
  while(parent_node != nullptr) {
    if(current_node != nullptr) {
      next_node = current_node->get_neighbor();
      delete current_node;
      current_node = next_node;
    } else {
      current_node = parent_node;
      parent_node = current_node->get_parent();
    }
  }
  delete current_node;
}
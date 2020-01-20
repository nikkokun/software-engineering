//
// Created by Nico Roble on 2020-01-17.
//

#include <block.h>

using namespace bptree;

int Block::get_key() {
  return Block::key;
}

int Block::set_key(int key) {
  Block::key = key;
  return Block::key;
}

int Block::get_value() {
  return Block::value;
}

int Block::set_value(int value) {
  Block::value = value;
  return Block::value;
}

Node* Block::get_left() {
  return Block::left;
}

Node* Block::set_left(Node* node) {
  Block::left = node;
  return Block::left;
}

Node* Block::get_right() {
  return Block::right;
}

Node* Block::set_right(Node* node) {
  Block::right = node;
  return Block::right;
}

Block::Block() {
  Block::key = -1;
  Block::left = nullptr;
  Block::right = nullptr;
}

Block::~Block() {
  Block::left = nullptr;
  Block::right = nullptr;
  Block::value = -1;
  Block::key = -1;
}
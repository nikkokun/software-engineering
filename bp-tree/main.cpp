#include <iostream>
#include <vector>
#include <bplustree.h>

using namespace std;
using namespace bptree;

int main() {

  auto bptree = new BPlusTree();
  for (int i = 1; i < 20; ++i) {
    bptree->insert(i);
    bptree->print_tree();
  }


  delete bptree;

  auto bptree2 = new BPlusTree();
  for (int i = 30; i > 0; --i) {
    bptree2->insert(i);
    bptree2->print_tree();
  }

  delete bptree2;

  auto bptree3 = new BPlusTree();
  for (int i = 1; i < 1000000; ++i) {
    bptree3->insert(i);
  }

  delete bptree3;

  return 0;
}
#include <iostream>
#include <vector>
#include <bplustree.h>

using namespace std;
using namespace bptree;

int main() {

  auto bptree = new BPlusTree();
  for (int i = 1; i < 1000000; ++i) {
    bptree->insert(i);
  }

  delete bptree;

  return 0;
}
#include <iostream>
#include <vector>
#include <bplustree.h>

using namespace std;
using namespace bptree;

int main() {
  std::cout << "Hello, World!" << std::endl;

  auto bptree = new BPlusTree();
  for (int i = 1; i < 1000000; ++i) {
    bptree->insert(i);
  }

  return 0;
}
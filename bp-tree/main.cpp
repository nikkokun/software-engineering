#include <iostream>
#include <vector>
#include <set>
#include <bplustree.h>

using namespace std;
using namespace bptree;

int main() {

  set<int> numbers;
  while (numbers.size() < 20)
  {
    numbers.insert(rand() % 100000);
  }
  auto bptree = new BPlusTree();
  for(auto number : numbers) {
    bptree->insert(number);
    bptree->print_tree();
  }

  auto bptree2 = new BPlusTree();
  for (int i = 1; i < 20; ++i) {
    bptree2->insert(i);
  }

  bptree2->print_tree();


  auto bptree3 = new BPlusTree();
  for (int i = 30; i > 0; --i) {
    bptree3->insert(i);
    bptree3->print_tree();
  }

  auto bptree4 = new BPlusTree();
  for (int i = 1; i < 1000000; ++i) {
    bptree4->insert(i);
  }
  delete bptree;
  delete bptree2;
  delete bptree3;
  delete bptree4;

  return 0;
}
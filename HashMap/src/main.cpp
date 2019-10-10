#include <iostream>
#include <SortedList.h>
#include <HashMap.h>
#include <utils.h>

using namespace std;

int main() {
  SortedList sorted_list = SortedList();
  HashMap hash_map = HashMap(1000);

  for(int i = 0; i < 10000; ++i) {
    int random_transaction = generate_random_transactions(1, 10000);
    sorted_list.insert(random_transaction);
    hash_map.insert(random_transaction);
  }

  vector<int> bin_search_array = sorted_list.to_vector();

  int query;

  do {
    query = 0;
    cout << "Enter a key(int)\n";
    cout << '>';
    cin >> query;
    cout << "Linear search took " << to_string(sorted_list.search(query)) << "steps \n";
    cout << "Binary Search took " << to_string(binary_search(bin_search_array, 0, bin_search_array.size() - 1, query, 1)) << " steps\n";
    cout << "Hash took " << to_string(hash_map.search(query)) << " steps \n";
  }while(query != -1);

}
//
// Created by Nico Roble on 2019-11-18.
//

#include <vector>
#include <random>

#ifndef OCC_UTILS_H
#define OCC_UTILS_H


vector<vector<int>> generate_random_transactions(vector<int> main_index, int num_transactions, int num_operations) {

  vector<vector<int>> random_indices;

  auto min = min_element(begin(main_index), end(main_index));
  auto max = max_element(begin(main_index), end(main_index));

  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distribution(*min, *max);

  for (int i = 0; i < num_transactions; ++i) {
    vector<int> operation_indices;
    for (int k = 0; k < num_operations; ++k) {
      operation_indices.push_back(distribution(eng));
    }
    random_indices.push_back(operation_indices);
  }

  return random_indices;
}

vector<vector<int>> sort_random_transactions(vector<vector<int>> random_transactions) {

  vector<vector<int>> sorted_transactions;
  for (int i = 0; i < random_transactions.size(); ++i) {
    vector<int> sorted_indices = random_transactions[i];
    sort(sorted_indices.begin(), sorted_indices.end());
    sorted_transactions.push_back(sorted_indices);
  }

  return sorted_transactions;

}

#endif //OCC_UTILS_H

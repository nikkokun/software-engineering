//
// Created by Nico Roble on 2019-10-07.
//

#ifndef HASHMAP_UTILS_H
#define HASHMAP_UTILS_H

#include <vector>
#include <random>

using namespace std;

int generate_random_transactions(int min, int max) {

  vector<vector<int>> random_indices;

  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distribution(min, max);

  return distribution(eng);

}

int binary_search(vector<int> data, int left_index, int right_index, int x, int count) {
  // recursive search
  if(right_index >= left_index) {
    int mid = left_index + (right_index - left_index) / 2;
    if(data[mid] == x) {
      return count;
    }

    if(data[mid] > x) {
      return binary_search(data, left_index, mid - 1, x, ++count);
    }

    return binary_search(data, mid + 1, right_index, x, ++count);
  }
  // no matches
  return -1;
}

#endif //HASHMAP_UTILS_H

//
// Created by Nico Roble on 2019-11-18.
//

#include <vector>
#include <map>

#ifndef OCC_THREADUTILS_H
#define OCC_THREADUTILS_H

bool is_intersect(vector<int> &v1,vector<int> &v2){
  vector<int> v3;

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  set_intersection(v1.begin(),v1.end(), v2.begin(),v2.end(), back_inserter(v3));

  return v3.empty()? true : false;
}

void worker(vector<Row> &table, vector<vector<int>> random_transactions, TransactionLog &transaction_log) {

  vector<vector<int>> sorted_transactions = sort_random_transactions(random_transactions);

  cout << "Finished sorting \n";

  while(!random_transactions.empty() && !sorted_transactions.empty()) {

    vector<int> read_set = sorted_transactions.front();
    vector<int> random_transaction = random_transactions.front();


    map<int, Row> local_data_copy;
    bool is_valid = true;
    read_set.erase(unique(read_set.begin(), read_set.end()), read_set.end());
    int tx_start_id = transaction_log.get_latest_record();

    //read phase
    for(int index : read_set) {
      Row &row = table[index];
      Row row_copy = Row(row.get_key(), row.get_data());
      local_data_copy.insert(pair<int, Row>(index, row_copy));
    }

    //validation phase
    //acquire giant lock
    transaction_log.global_lock.lock();
    int tx_end_id = transaction_log.get_latest_record();

    //garbage collection section
    transaction_log.collect_garbage();

    // check validity
    for(int i = tx_start_id + 1; i < tx_end_id; ++i) {
      vector<int> previous_transaction_write_set = transaction_log.get_record(i).get_write_set();
      is_intersect(previous_transaction_write_set, read_set) ? is_valid = true : is_valid = false;
    }

    //write phase
    if(is_valid) {
      for(int index : random_transaction) {
        Row row = local_data_copy.at(index);
        int row_data = row.get_data();
        row_data += 1;
        row.set_data(row_data);
      }

      //write
      for(int index : read_set) {
        Row row = local_data_copy.at(index);
        table[index].set_data(row.get_data());
      }
      //count up log
      transaction_log.push_back_record(read_set);

    } else {
      sorted_transactions.push_back(read_set);
      random_transactions.push_back(random_transaction);
    }

    //finish transaction
    sorted_transactions.erase(sorted_transactions.begin());
    random_transactions.erase(random_transactions.begin());
    transaction_log.global_lock.unlock();
  }
}

#endif //OCC_THREADUTILS_H

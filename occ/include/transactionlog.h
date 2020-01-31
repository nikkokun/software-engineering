//
// Created by Nico Roble on 2019-11-18.
//

#include <vector>
#include <transactionrecord.h>

#ifndef OCC_TRANSACTIONLOG_H
#define OCC_TRANSACTIONLOG_H

using namespace std;

class TransactionLog {
  // used to store all transactions
 private:
  vector<TransactionRecord> records;
  string name;

 public:
  mutable mutex global_lock;

  TransactionRecord get_record(int index) {
    return records[index];
  }

  int get_latest_record() {
    return records.size() - 1;
  }

  void push_back_record(vector<int> write_set) {
    TransactionRecord new_record = TransactionRecord(get_latest_record() + 1, write_set);
  };

  void collect_garbage() {
    int latest_record = TransactionLog::get_latest_record();
    for(int i = 0; i < latest_record; ++i) {
      TransactionLog::records.erase(TransactionLog::records.begin());
    }
  }

  TransactionLog(TransactionLog const &transaction_log) {
    TransactionLog::records = transaction_log.records;
  }

  TransactionLog(string name) {
    TransactionLog::name = name;
  }

};


#endif //OCC_TRANSACTIONLOG_H

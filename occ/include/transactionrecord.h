//
// Created by Nico Roble on 2019-11-18.
//

#include <vector>

#ifndef OCC_TRANSACTONRECORD_H
#define OCC_TRANSACTONRECORD_H

using namespace std;

class TransactionRecord {
  // Store transaction records, basic unit for a transaction log.
 private:
  int id;
  vector<int> write_set;

 public:
  int get_id() const {
    return id;
  }
  void set_id(int id) {
    TransactionRecord::id = id;
  }
  vector<int> get_write_set() const {
    return write_set;
  }
  void set_write_set(vector<int> accessedRecordId) {
    write_set = accessedRecordId;
  }

  TransactionRecord(int id, vector<int> write_set) {
    TransactionRecord::id = id;
    TransactionRecord::write_set = write_set;
  }

};


#endif //OCC_TRANSACTONRECORD_H

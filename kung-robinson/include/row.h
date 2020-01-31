//
// Created by Nico Roble on 2019-11-18.
//

#ifndef OCC_ROW_H
#define OCC_ROW_H

class Row {
  // represents a row in the database
 private:
  int key;
  int data;

 public:
  int get_key() const {
    return key;
  }
  void set_key(int key) {
    Row::key = key;
  }
  int get_data() const {
    return data;
  }
  void set_data(int data) {
    Row::data = data;
  }

  Row(int k, int d) {
    Row::key = k;
    Row::data = d;
  }

};


#endif //OCC_ROW_H

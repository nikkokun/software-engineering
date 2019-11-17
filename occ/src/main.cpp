#include <iostream>
#include <vector>
#include <thread>
#include <transactionlog.h>
#include <row.h>
#include <utils.h>
#include <threadutils.h>

using namespace std;

int main() {

  const int NUM_TRANSACTIONS = 10000;
  const int NUM_ROWS = 10000;
  const int NUM_OPERATIONS = 20;
  const int NUM_THREADS = 4;
  int thread_id = 0;
  double time;

  vector<thread> threads(NUM_THREADS);
  vector<Row> table;
  vector<int> indices;
  vector<vector<vector<int>>> thread_transactions;

  TransactionLog transaction_log = TransactionLog("log");

  for(int i=0; i < NUM_ROWS; ++i) {
    Row row = Row(i, 0);
    table.push_back(row);
  }

  u_long size = table.size();

  for(int i=0; i < size; ++i) {
    indices.push_back(i);
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    thread_transactions.push_back(generate_random_transactions(indices, NUM_TRANSACTIONS, NUM_OPERATIONS));
  }

  cout << "Starting...\n";


  chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
  //main
  for (std::thread &t : threads) {
    t = thread(worker, ref(table), thread_transactions[thread_id], ref(transaction_log));
    ++thread_id;
  }

  for (std::thread &t : threads) {
    t.join();
  }


  chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
  time = chrono::duration_cast<chrono::microseconds>(end - start).count();
  cout << "Finished after " << time << " microseconds \n";


  return 0;
}
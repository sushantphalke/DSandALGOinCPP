#include <bits/stdc++.h>
#include <semaphore.h>

// #include <ctime>
// #include <iostream>
// #include <mutex>
// #include <queue>
// #include <thread>
// #include <vector>

using namespace std;

class Customer {
 public:
  int id;
  string work;
  time_t timestamp;

  Customer(int _id, string _work) : id(_id), work(_work), timestamp(0) {}
};

class Manager {
 public:
  int id;

  Manager(int _id) : id(_id) {}
};

class ServiceCenter {
 public:
  sem_t sema;
  queue<Customer> customers;
  vector<Manager> managers;
  mutex mtx;
  int next_manager;

  ServiceCenter(int num_managers) : next_manager(0) {
    sem_init(&sema, 0, num_managers);
    for (int i = 0; i < num_managers; ++i) {
      managers.emplace_back(i);
    }
  }

  void handleCustomer(Customer &customer) {
    sem_wait(&sema);
    Manager &manager = managers[getNextManager()];
    customer.timestamp = time(nullptr);
    mtx.lock();
    cout << "Customer " << customer.id << " requests assistance for work '" << customer.work
         << " and is assigned to Manager " << manager.id << "' at " << ctime(&customer.timestamp) << endl;

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Customer " << customer.id << " completed chat with Manager " << manager.id << " at "
         << ctime(&customer.timestamp) << "\n-------------------------------------------" << endl;
    mtx.unlock();
    sem_post(&sema);  // Release the thread for another process
  }

  int getNextManager() {
    int current_manager = next_manager;
    next_manager = (next_manager + 1) % managers.size();
    return current_manager;
  }
};

void customerThread(int id, ServiceCenter &serviceCenter) {
  string work = "Work" + to_string(id);
  Customer customer(id, work);
  serviceCenter.handleCustomer(customer);
}

int main() {
  int num_customers = 5;
  int num_managers = 3;

  ServiceCenter serviceCenter(num_managers);

  vector<thread> customerThreads;
  for (int i = 0; i < num_customers; ++i) {
    customerThreads.emplace_back(customerThread, i, ref(serviceCenter));
  }

  for (auto &thread : customerThreads) {
    thread.join();
  }

  return 0;
}

#include <bits/stdc++.h>
#include <semaphore.h>

#include <ctime>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
using namespace std;
mutex mtx;

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
  queue<Customer> Customers;
  vector<Manager> managers;
  mutex mtx;
  int next_manager;

  ServiceCenter(int num_Customers) : next_manager(0) {
    sem_init(&sema, 0, num_Customers);
    for (int i = 0; i < num_Customers; ++i) {
      managers.emplace_back(i);
    }
  }

  void handleCustomer(Customer &Customer) {
    sem_wait(&sema);
    Manager &manager = managers[getNextManager()];
    Customer.timestamp = time(nullptr);
    mtx.lock();
    cout << "Customer " << Customer.id << " requests assistance for work '" << Customer.work
         << " and is assigned to Manager " << manager.id << "' at " << ctime(&Customer.timestamp) << endl;

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Customer " << Customer.id << " completed chat with Manager " << manager.id << " at "
         << ctime(&Customer.timestamp) << "\n-------------------------------------------" << endl;
    mtx.unlock();
    sem_destroy(&sema);  // lets layoff some managers also and hire new for another Customer.
    // destroying the thread and creating new for another task in next iteration.
  }

  int getNextManager() {
    int current_manager = next_manager;
    next_manager = next_manager + 1;
    return current_manager;
  }
};

void CustomerThread(int id, ServiceCenter &serviceCenter) {
  string work = "Work" + to_string(id);
  Customer Customer(id, work);
  serviceCenter.handleCustomer(Customer);
}

int main() {
  int num_Customers = 5;
  int num_managers = 3;

  ServiceCenter serviceCenter(num_Customers);

  vector<thread> CustomerThreads;
  for (int i = 0; i <= num_Customers; ++i) {
    CustomerThreads.emplace_back(CustomerThread, i, ref(serviceCenter));
  }

  for (auto &thread : CustomerThreads) {
    thread.join();
  }

  return 0;
}

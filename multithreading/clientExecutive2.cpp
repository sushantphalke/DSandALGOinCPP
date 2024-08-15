#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
mutex mtx;  // Mutex for synchronization
condition_variable cv;

class Controller {
 private:
  int numExecutives_;
  int executivesAvailable_ = numExecutives_;
  int nextExecutive_ = 1;

  string getTimeStamp() {
    auto now = chrono::system_clock::now();
    time_t timestamp = chrono::system_clock::to_time_t(now);
    return ctime(&timestamp);
  }

 public:
  Controller(int numExecutives) : numExecutives_(numExecutives) {}

  void assignTaskToExecutive(int clientId, string keyword) {
    mtx.lock();
    while (executivesAvailable_ == 0) {
      
      cout << "No available executives for Client " << clientId << ". Please wait." << endl;
      this_thread::sleep_for(chrono::seconds(1));
      
    }

    executivesAvailable_--;
    int executiveId = nextExecutive_;
    nextExecutive_ = nextExecutive_ + 1;

    cout << "Assigned Client " << clientId << " to Executive " << executiveId << " at timestamp " << getTimeStamp() << endl;
    mtx.unlock();
    this_thread::sleep_for(chrono::seconds(0));  // Simulate processing

    mtx.lock();
    executivesAvailable_++;
    mtx.unlock();
  }
};

void clientThread(Controller& controller, int clientId, string keyword) {
  controller.assignTaskToExecutive(clientId, keyword);
}

int main() {
  const int numExecutives = 2;
  Controller controller(numExecutives);

  vector<thread> clientThreads;
  const int numClients = 4;

  // Simulate clients making requests
  for (int i = 1; i <= numClients; ++i) {
    string keyword = "Keyword" + to_string(i);
    clientThreads.push_back(thread(clientThread, ref(controller), i, keyword));
  }

  // Wait for all client threads to finish
  for (auto& thread : clientThreads) {
    thread.join();
  }

  return 0;
}

// // Case2_OneExecutiveHandlesMultipleClients.cpp

// #include <iostream>
// #include <vector>
// #include <thread>
// #include <string>
// #include <chrono>

// const int NUM_EXECUTIVES = 3;
// const int NUM_CLIENTS = 5;

// struct Message {
//     int clientId;
//     string keyword;
// };

// class Executive {
// public:
//     void handleRequest(const Message& message) {
//         cout << "Executive is handling Client " << message.clientId << "'s request with keyword: " << message.keyword << endl;
//         // Simulate processing
//         this_thread::sleep_for(chrono::seconds(2));
//         cout << "Executive has completed Client " << message.clientId << "'s request." << endl;
//     }
// };

// void clientThread(Executive& executive, int clientId, string keyword) {
//     Message message;
//     message.clientId = clientId;
//     message.keyword = keyword;
//     executive.handleRequest(message);
// }

// int main() {
//     Executive executive;

//     // Simulate clients making requests
//     vector<thread> clientThreads;
//     for (int i = 1; i <= NUM_CLIENTS; ++i) {
//         string keyword = "Keyword" + to_string(i);
//         clientThreads.emplace_back(clientThread, ref(executive), i, keyword);
//     }

//     // Wait for client threads to finish
//     for (auto& thread : clientThreads) {
//         thread.join();
//     }

//     return 0;
// }
#include <bits/stdc++.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
mutex mtx;  // Mutex for synchronization

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
    if (executivesAvailable_ > 0) {
      executivesAvailable_--;
      int executiveId = nextExecutive_;
      nextExecutive_ = (nextExecutive_ % numExecutives_) + 1;
      mtx.unlock();

      cout << "\nClient " << clientId;
      cout << " requests search for keyword: '" << keyword << "'" << endl;
      this_thread::sleep_for(chrono::seconds(2));  // Simulate processing

      mtx.lock();
      executivesAvailable_++;
      mtx.unlock();

      cout << getTimeStamp() << "\nClient " << clientId;
      cout << " served by Executive " << executiveId  << endl;
    } else {
      mtx.unlock();
      cout << "\nClient " << clientId << " is waiting for an available executive..." << endl;
    }
  }
};

void clientThread(Controller& controller, int clientId, string keyword) {
  controller.assignTaskToExecutive(clientId, keyword);
}

int main() {
  const int numExecutives = 3;
  Controller controller(numExecutives);

  vector<thread> clientThreads;
  const int numClients = 5;

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

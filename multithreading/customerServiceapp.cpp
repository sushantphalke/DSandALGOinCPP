#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include<bits/stdc++.h>
using namespace std;

mutex mtx; // Mutex for synchronization

class Controller {
public:
    Controller(int numExecutives) : numExecutives_(numExecutives) {}

    void assignTaskToExecutive(int clientId, string keyword) {
        mtx.lock();
        if (executivesAvailable_ > 0) {
            executivesAvailable_--;
            cout << "Assigned Client " << clientId << " to Executive " << nextExecutive_ << " at timestamp " << getTimeStamp() << endl;
            this_thread::sleep_for(chrono::milliseconds(200)); // Simulate processing
            executivesAvailable_++;
        } else {
            cout << "No available executives for Client " << clientId << ". Please wait." << endl;
        }
        mtx.unlock();
    }

private:
    int numExecutives_;
    int executivesAvailable_ = numExecutives_;
    int nextExecutive_ = 1;

    string getTimeStamp() {
        auto now = chrono::system_clock::now();
        time_t timestamp = chrono::system_clock::to_time_t(now);
        return ctime(&timestamp);
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

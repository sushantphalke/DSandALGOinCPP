#include <iostream>
#include <string>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

const int NUM_EXECUTIVES = 3;
const int NUM_CLIENTS = 5;

struct Message {
    int clientId;
    std::string keyword;
};

class Controller {
public:
    void assignTaskToExecutive(const Message& message) {
        std::cout << "Assigned Client " << message.clientId << " to an executive with keyword: " << message.keyword << std::endl;
        // Simulate processing
        Sleep(2000); // Sleep for 2 seconds to simulate processing
        std::cout << "Task for Client " << message.clientId << " has been completed." << std::endl;
    }
};

void clientThread(Controller& controller, int clientId, std::string keyword) {
    Message message;
    message.clientId = clientId;
    message.keyword = keyword;
    controller.assignTaskToExecutive(message);
}

int main() {
    Controller controller;

    // Simulate clients making requests
    std::vector<std::thread> clientThreads;
    for (int i = 1; i <= NUM_CLIENTS; ++i) {
        std::string keyword = "Keyword" + std::to_string(i);
        clientThreads.emplace_back(clientThread, std::ref(controller), i, keyword);
    }

    // Wait for client threads to finish
    for (auto& thread : clientThreads) {
        thread.join();
    }

    return 0;
}

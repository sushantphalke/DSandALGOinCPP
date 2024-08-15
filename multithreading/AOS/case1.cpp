// Case1_OneExecutivePerClient.cpp

#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <chrono>

const int NUM_EXECUTIVES = 3;
const int NUM_CLIENTS = 5;

struct Message {
    int clientId;
    std::string keyword;
};

class Executive {
public:
    void handleRequest(const Message& message) {
        std::cout << "Executive is handling Client " << message.clientId << "'s request with keyword: " << message.keyword << std::endl;
        // Simulate processing
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Executive has completed Client " << message.clientId << "'s request." << std::endl;
    }
};

void clientThread(Executive& executive, int clientId, std::string keyword) {
    Message message;
    message.clientId = clientId;
    message.keyword = keyword;
    executive.handleRequest(message);
}

int main() {
    Executive executives[NUM_EXECUTIVES];

    // Simulate clients making requests
    std::vector<std::thread> clientThreads;
    for (int i = 1; i <= NUM_CLIENTS; ++i) {
        std::string keyword = "Keyword" + std::to_string(i);
        clientThreads.emplace_back(clientThread, std::ref(executives[i % NUM_EXECUTIVES]), i, keyword);
    }

    // Wait for client threads to finish
    for (auto& thread : clientThreads) {
        thread.join();
    }

    return 0;
}

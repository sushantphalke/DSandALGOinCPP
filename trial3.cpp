// #include <iostream>
// #include <thread>
// #include <vector>
// #include <mutex>
#include <bits/stdc++.h>
using namespace std;

 mutex mtx;  // Mutex for thread synchronization

const int M = 5;  // Number of client processes
const int N = 3;  // Number of executive processes

// Shared FAQ document
 string faqDocument = "Frequently Asked Questions:\n1. How can I reset my password?\n2. What is the return policy?\n3. ...";

// Function to simulate an executive process
void executive(int id) {
    while (true) {
         this_thread::sleep_for( chrono::seconds(2));  // Simulate work
        
        // Implement logic to check if the executive is available for new clients
        {
             lock_guard< mutex> lock(mtx);
             cout << "Executive " << id << " is available.\n";
        }
    }
}

// Function to simulate a client process
void client(int id, int execId) {
    // Simulate sending a request to the controller
    {
         lock_guard< mutex> lock(mtx);
         cout << "Client " << id << " requests assistance from Executive " << execId << ".\n";
    }

    // Simulate conversation with the executive
     this_thread::sleep_for( chrono::seconds(4));  // Simulate conversation

    // Simulate closing the conversation and releasing the executive
    {
         lock_guard< mutex> lock(mtx);
         cout << "Client " << id << " conversation with Executive " << execId << " completed.\n";
    }
}

int main() {
    // Create executive threads
     vector< thread> executiveThreads;
    for (int i = 0; i < N; ++i) {
        executiveThreads.emplace_back(executive, i);
    }

    // Create client threads
     vector< thread> clientThreads;
    for (int i = 0; i < M; ++i) {
        int execId = i % N;  // Assign clients to executives sequentially
        clientThreads.emplace_back(client, i, execId);
    }

    // Join client threads
    for (auto& thread : clientThreads) {
        thread.join();
    }

    // Join executive threads
    for (auto& thread : executiveThreads) {
        thread.join();
    }

    return 0;
}

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <ctime>
#include <iomanip>

const int NUM_RESOURCES = 3;  // Number of resource types
const int NUM_PROCESSES = 8;  // Number of processes

std::mutex mtx; // Mutex for resource allocation

std::vector<int> available(NUM_RESOURCES, 0);
std::vector<std::vector<int>> maximum(NUM_PROCESSES, std::vector<int>(NUM_RESOURCES, 0));
std::vector<std::vector<int>> allocation(NUM_PROCESSES, std::vector<int>(NUM_RESOURCES, 0));
std::vector<std::vector<int>> need(NUM_PROCESSES, std::vector<int>(NUM_RESOURCES, 0));

std::vector<std::thread> threads;

std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void requestResource(int processID, const std::vector<int>& request) {
    std::unique_lock<std::mutex> lock(mtx);
    
    // Check if the requested resources are less than or equal to the need
    bool safe = true;
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        if (request[i] > need[processID][i] || request[i] > available[i]) {
            safe = false;
            break;
        }
    }
    
    if (safe) {
        // Temporarily allocate the requested resources
        for (int i = 0; i < NUM_RESOURCES; ++i) {
            available[i] -= request[i];
            allocation[processID][i] += request[i];
            need[processID][i] -= request[i];
        }
        
        // Check if the system is in a safe state
        // You can implement the Banker's Algorithm safety check here
        
        // If safe, grant the resources and proceed
        std::cout << "[" << getCurrentTime() << "] Process " << processID + 1 << " requested resources and was granted." << std::endl;
    } else {
        std::cout << "[" << getCurrentTime() << "] Process " << processID + 1 << " requested resources but was denied." << std::endl;
    }
    
    // Release the lock
    lock.unlock();
}

void releaseResource(int processID, const std::vector<int>& release) {
    std::unique_lock<std::mutex> lock(mtx);
    
    // Release the allocated resources
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        available[i] += release[i];
        allocation[processID][i] -= release[i];
        need[processID][i] += release[i];
    }
    
    // Notify other threads about the released resources
    
    // Release the lock
    lock.unlock();
}

int main() {
    // Initialize available resources, maximum claims, and need matrix
    available = {3, 3, 2};

    maximum = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3},
        {5, 5, 2},
        {7, 1, 1},
        {0, 1, 0}
    };
    
    // Create threads representing processes
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        threads.push_back(std::thread([i]() {
            // Simulate resource request and release
            std::vector<int> request(NUM_RESOURCES, 0);
            std::vector<int> release(NUM_RESOURCES, 0);
            
            // Simulate different requests and releases
            if (i == 0) {
                request[0] = 3; // Request 3 of resource type 1
            } else if (i == 1) {
                request[1] = 2; // Request 2 of resource type 2
            } else if (i == 2) {
                request[2] = 2; // Request 2 of resource type 3
            } else if (i == 3) {
                request[0] = 1; // Request 1 of resource type 1
                request[1] = 1; // Request 1 of resource type 2
                request[2] = 1; // Request 1 of resource type 3
            } else {
                release[0] = 1; // Release 1 of resource type 1
                release[2] = 1; // Release 1 of resource type 3
            }
            
            // Simulate requests and releases
            requestResource(i, request);
            releaseResource(i, release);
        }));
    }
    
    // Join threads
    for (auto& thread : threads) {
        thread.join();
    }
    
    return 0;
}
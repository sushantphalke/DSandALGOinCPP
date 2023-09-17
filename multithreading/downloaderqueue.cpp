#include <bits/stdc++.h>

#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
using namespace std;

mutex mtx;  // Mutex for thread synchronization

const int MAX_THREADS = 3;    // Maximum number of active downloader threads
queue<string> downloadQueue;  // Download queue

// Function to simulate file downloading
void downloadFile(const string& filename) {
  // Simulate downloading by sleeping for a few seconds
  this_thread::sleep_for(chrono::seconds(2));

  // Simulate progress update
  lock_guard<mutex> lock(mtx);
  cout << "Downloaded: " << filename << endl;
}

// Downloader thread function
void downloader(int id) {
  while (true) {
    string filename;
    {
      lock_guard<mutex> lock(mtx);
      if (!downloadQueue.empty()) {
        filename = downloadQueue.front();
        downloadQueue.pop();
      }
    }

    if (!filename.empty()) {
      downloadFile(filename);
    } else {
      // No more work in the queue, thread can exit
      break;
    }
  }
}

int main() {
  vector<thread> threads;

  // Populate the download queue with sample files
  downloadQueue.push("file1.txt");
  downloadQueue.push("file2.txt");
  downloadQueue.push("file3.txt");
  downloadQueue.push("file4.txt");
  downloadQueue.push("file5.txt");
  downloadQueue.push("file6.txt");
  downloadQueue.push("file7.txt");
  downloadQueue.push("file8.txt");

  // Create downloader threads
  for (int i = 0; i < MAX_THREADS; ++i) {
    threads.emplace_back(downloader, i);
  }

  // Join downloader threads
  for (auto& thread : threads) {
    thread.join();
  }

  return 0;
}

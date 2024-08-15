#include <bits/stdc++.h>

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
using namespace std;

class FileDownloader {
 public:
  FileDownloader(const string& url, const string& filename)
      : url_(url), filename_(filename) {}

  void download() {
    
    // Simulate file download by sleeping for a few seconds
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Downloaded: " << url_ << endl;

    // Simulate saving the downloaded content to a file
    saveToFile();
  }

  void saveToFile() {
    // Simulate saving to a file by writing the current timestamp
    auto now = chrono::system_clock::now();
    auto timestamp = chrono::system_clock::to_time_t(now);

    ofstream file(filename_);
    file << "Downloaded content from " << url_ << " at " << ctime(&timestamp);
    file.close();

    cout << "Saved to: " << filename_ << endl;
  }

 private:
  string url_;
  string filename_;
};

class ThreadPool {
 public:
  ThreadPool(int num_threads) {
    for (int i = 0; i < num_threads; ++i) {
      threads_.emplace_back(&ThreadPool::worker, this);
    }
  }

  ~ThreadPool() {
    for (auto& thread : threads_) {
      thread.join();
    }
  }

  void enqueue(FileDownloader downloader) {
    unique_lock<mutex> lock(queue_mutex_);
    download_queue_.push(move(downloader));
    lock.unlock();
    condition_.notify_one();
  }

 private:
  void worker() {
    while (true) {
      unique_lock<mutex> lock(queue_mutex_);
      condition_.wait(lock, [this] { return !download_queue_.empty(); });

      if (!download_queue_.empty()) {
        FileDownloader downloader = move(download_queue_.front());
        download_queue_.pop();
        lock.unlock();

        downloader.download();
      }
    }
  }

  vector<thread> threads_;
  queue<FileDownloader> download_queue_;
  mutex queue_mutex_;
  condition_variable condition_;
};

int main() {
  ThreadPool thread_pool(4);  // Create a thread pool with 4 threads

  // List of URLs to download
  vector<string> urls = {
      "https://drive.google.com/file/d/1Alv1zYyuoOOerZ6Wm90jtVHALlURYtut/view?usp=sharing",
      "https://drive.google.com/file/d/1pSBj0Y8uZyiyZfiti5mwaYmc4EmykV2R/view?usp=sharing",
      "https://docs.google.com/document/d/1yAXR0W1Un4JdcFHmJguni5kO-zcJm2NisM2_EBJ7bXo/edit",
      "https://docs.google.com/document/d/1yAXR0W1Un4JdcFHmJguni5kO-zcJm2NisM2_EBJ7bXo/edit"};

  for (const string& url : urls) {
    string filename = "download_" + to_string(chrono::system_clock::now().time_since_epoch().count()) + ".txt";
    FileDownloader downloader(url, filename);
    thread_pool.enqueue(downloader);
    //    lock.unlock();
  }

  // Sleep to allow downloads to complete
  this_thread::sleep_for(chrono::seconds(2));

  return 0;
}

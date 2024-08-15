#include <bits/stdc++.h>
using namespace std;
class solution {
  vector<int> tasks;
  int sessionTime;
  int result;
  vector<int> sessions;
  void dfs(int idx) {
    if (sessions.size() >= result) {
      return;
    }
    if (idx == tasks.size()) {
      result = sessions.size();
      return;
    }
    for (int i = 0; i < sessions.size(); i++) {
      if (sessions[i] + tasks[idx] <= sessionTime) {
        sessions[i] += tasks[idx];
        dfs(idx + 1);
        sessions[i] -= tasks[idx];
      }
    }
    sessions.push_back(tasks[idx]);
    dfs(idx + 1);
    sessions.pop_back();
  }

 public:
  int minSessions(vector<int>& tasks, int sessionTime) {
    this->tasks = tasks;
    this->sessionTime = sessionTime;
    result = tasks.size();
    dfs(0);
    return result;
  }
};
int main() {
  //   vector<int> arr = {4, 8, 1, 4, 2, 1};
  vector<int> v = {60, 10, 40, 80,60, 10, 40, 80,10,10,10};
  int C = 100;
  solution s1;
  int k =150;
  cout << "Minimum number of bins required are : " << s1.minSessions(v, C)*k<< endl;
}
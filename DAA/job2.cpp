#include <bits/stdc++.h>
using namespace std;


struct Job {
  char id;
  int dead;
  int profit;
};

void printJobScheduling(Job  arr) {
  sort(arr, arr + n, comparison);

  int result[n];
  bool slot[n];

  for (int i = 0; i < n; i++)
    slot[i] = false;

  for (int i = 0; i < n; i++) {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
      if (slot[j] == false) {
        result[j] = i;
        slot[j] = true;
        break;
      }
    }
  }

  // Print the result
  for (int i = 0; i < n; i++)
    if (slot[i])
      cout << arr[result[i]].id << " ";
}


int main() {
  vector<vector<int>> arr ={{'a', 2, 100},
                          {'b', 1, 19},
                          {'c', 2, 27},
                          {'d', 1, 25},
                          {'e', 3, 15}};

  printJobScheduling(arr);

  return 0;
}
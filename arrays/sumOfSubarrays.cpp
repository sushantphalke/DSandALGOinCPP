#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[5] = {3,
                2,
                4,
                1,
                -3};
  int n = 5;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    // cout << "__________" << endl;
    for (int j = i; j < n; j++) {
      sum = sum + arr[j]; 
      cout << sum << endl;
      // cout << "__________" << endl;
      counter++;
    }
  }
  cout << "no of subarrays : " << counter;
  return 0;
}
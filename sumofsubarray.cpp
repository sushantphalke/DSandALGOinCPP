
#include <bits/stdc++.h>
using namespace std;

// Function to find number of subarrays with sum exactly
// equal to k.
int findSubarraySum(int arr[], int n, int sum) {
  // STL map to store number of subarrays starting from
  // index zero having particular value of sum.
  unordered_map<int, int> prevSum;

  int res = 0;

  // Sum of elements so far.
  int currSum = 0;

  for (int i = 0; i < n; i++) {
    // Add current element to sum so far.
    currSum += arr[i];

    // If currsum is equal to desired sum, then a new
    // subarray is found. So increase count of
    // subarrays.
    if (currSum == sum)
      res++;

    // currsum exceeds given sum by currsum - sum. Find
    // number of subarrays having this sum and exclude
    // those subarrays from currsum by increasing count
    // by same amount.
    if (prevSum.find(currSum - sum) != prevSum.end())
      res += (prevSum[currSum - sum]);

    // Add currsum value to count of different values of
    // sum.
    prevSum[currSum]++;
  }

  return res;
}

int main() {
  int arr[] = {10, 2, -2, -20, 10};
  int sum = -10;
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << findSubarraySum(arr, n, sum);
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void printarr(vector<int> &v) {
//   for (auto x : v) {
//     cout << x << endl;

//   }
//   cout<<"next";
// }

// int main() {
//   vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//   int n = arr.size();

//   vector<int> v;
//   for (int i = 0; i < n; i++) {
//     v = {};
//     v.push_back(arr[i]);
//     int sum = arr[i];
//     for (int j = i + 1; j < n; j++) {
//       v.push_back(arr[j]);
//       sum += arr[j];
//       if (sum == 6) {
//         printarr(v);
//         break;
//       }
//     }
//   }

//   return 0;
// }
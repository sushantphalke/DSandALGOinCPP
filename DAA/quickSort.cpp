/* C++ implementation of QuickSort */

#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  vector<int> arr = {10, 7, 8, 9, 1, 5};

  int n = arr.size();

  quickSort(arr, 0, n - 1);

  cout << "Sorted array: \n";
  for (auto s : arr) {
    cout << s << ", ";
  }
  return 0;
}

//  Time complexity of quick sort is O(nlogn)

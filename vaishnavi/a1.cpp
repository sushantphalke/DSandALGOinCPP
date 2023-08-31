#include <omp.h>
#include <iostream>
using namespace std;

void parallel_min(int *arr, int n) {
  int min_val = arr[0];
#pragma omp parallel for reduction(min : min_val);
  for (int i = 1; i < n; i++) {
    if (arr[i] < min_val) {
      min_val = arr[i];
    }
  }
  cout << "\nmin=" << min_val;
}
void parallel_max(int *arr, int n) {
  int max_val = arr[0];
#pragma omp parallel for reduction(max : max_val);
  for (int i = 1; i < n; i++) {
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }
  cout << "\nmax=" << max_val;
}
void parallel_sum(int *arr, int n) {
  int sum = 0;
#pragma omp parallel for reduction(+ : sum);
  for (int i = 0; i < n; i++) {
    sum = sum + arr[i];
  }
  cout << "\nsum=" << sum;
  double avg = double(sum) / double(n);
  cout << "\navg=" << avg;
}

int main() {
  int arr[] = {101, 12, 33, 224, 520};
  parallel_min(arr, sizeof(arr) / sizeof(arr[0]));
  parallel_max(arr, sizeof(arr) / sizeof(arr[0]));
  parallel_sum(arr, sizeof(arr) / sizeof(arr[0]));
}
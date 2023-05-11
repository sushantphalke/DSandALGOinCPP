#include <omp.h>

#include <iostream>

using namespace std;

void parallel_min(int *arr, int n) {
  int min_val = arr[0];

#pragma omp parallel for reduction(min : min_val)
  for (int i = 1; i < n; i++) {
    if (arr[i] < min_val) {
      min_val = arr[i];
    }
  }

  cout << "Minimum value in the array: " << min_val << endl;
}

void parallel_max(int *arr, int n) {
  int max_val = arr[0];

#pragma omp parallel for reduction(max : max_val)
  for (int i = 1; i < n; i++) {
    if (arr[i] > max_val) {
      max_val = arr[i];
    }
  }

  cout << "Maximum value in the array: " << max_val << endl;
}

void parallel_sum(int *arr, int n) {
  int sum = 0;

#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  cout << "Sum of the array elements: " << sum << endl;
}

void parallel_avg(int *arr, int n) {
  int sum = 0;

#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  double avg = static_cast<double>(sum) / static_cast<double>(n);

  cout << "Average value of the array elements: " << avg << endl;
}

int main() {
  int arr[] = {5, 2, 9, 1, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  parallel_min(arr, n);
  parallel_max(arr, n);
  parallel_sum(arr, n);
  parallel_avg(arr, n);

  return 0;
}

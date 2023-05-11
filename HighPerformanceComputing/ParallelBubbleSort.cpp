#include <omp.h>

#include <iostream>

using namespace std;

void parallel_bubble_sort(int *arr, int n) {
  int i, j, temp;
  bool swapped;
#pragma omp parallel num_threads(4) shared(arr, n) private(i, j, temp, swapped)
  {
    for (i = 0; i < n - 1; i++) {
      swapped = false;
#pragma omp for
      for (j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
          swapped = true;
        }
      }
      if (!swapped) break;
    }
  }
}

int main() {
  int arr[] = {5, 2, 9, 1, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Before sorting: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  parallel_bubble_sort(arr, n);

  cout << "Parallel Bubble Sort using OpenMP After sorting: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

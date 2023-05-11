#include <omp.h>

#include <cstdlib>
#include <iostream>

using namespace std;

void quicksort(int *arr, int left, int right);
int partition(int *arr, int left, int right);

void parallel_quicksort(int *arr, int left, int right, int threshold) {
  if (left < right) {
    if (right - left < threshold) {
      quicksort(arr, left, right);
    } else {
      int pivot = partition(arr, left, right);

#pragma omp parallel sections
      {
#pragma omp section
        parallel_quicksort(arr, left, pivot - 1, threshold);
#pragma omp section
        parallel_quicksort(arr, pivot + 1, right, threshold);
      }
    }
  }
}

void quicksort(int *arr, int left, int right) {
  if (left < right) {
    int pivot = partition(arr, left, right);
    quicksort(arr, left, pivot - 1);
    quicksort(arr, pivot + 1, right);
  }
}

int partition(int *arr, int left, int right) {
  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[right]);
  return i + 1;
}

int main() {
  const int size = 6;
  int arr[size] = {5, 2, 9, 1, 5, 6};

  cout << "Unsorted array: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  parallel_quicksort(arr, 0, size - 1, 1000);

  cout << "\nParallel Quick Sort using OpenMP Sorted array: ";
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}

#include <omp.h>
#include <stdio.h>

#include <cstdlib>
#include <iostream>

#define MAX 100

using namespace std;  // Add this line to use cout and endl

int main() {
  int r = 3, c = 2;
  int matrix[r][c], vector[c], out[r];

  for (int row = 0; row < r; row++) {
    for (int col = 0; col < c; col++) {
      matrix[row][col] = 1;
    }
  }

  cout << "Input Matrix" << endl;  // Use endl instead of end1
  for (int row = 0; row < r; row++) {
    for (int col = 0; col < c; col++) {
      cout << "\t" << matrix[row][col];
    }
    cout << "" << endl;  // Use endl instead of end1
  }

  for (int col = 0; col < c; col++)  // Change row to col
  {
    vector[col] = 2;
  }
  cout << "Input Col-Vector" << endl;  // Use endl instead of end1
  for (int col = 0; col < c; col++)    // Change row to col
  {
    cout << vector[col] << endl;  // Use endl instead of end1
  }
#pragma omp parallel  // Move the parallel region outside the for loop
  {
#pragma omp for  // Remove the inner parallel region
    for (int row = 0; row < r; row++) {
      out[row] = 0;
      for (int col = 0; col < c; col++)  // Remove comma from for loop
      {
        out[row] += matrix[row][col] * vector[col];
      }
    }
  }
  cout << "Resultant Col-Vector" << endl;  // Use endl instead of end1
  for (int row = 0; row < r; row++) {
    cout << "\nvector[" << row << "]:" << out[row] << endl;  // Use endl instead of end1
  }
  return 0;
}

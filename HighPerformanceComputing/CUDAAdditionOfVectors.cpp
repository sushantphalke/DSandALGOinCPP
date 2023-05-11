#include <omp.h>
#include <stdio.h>

#include <cstdlib>/* CUDA Library */
#include <iostream>

#define MAX 100

int main() {
  int m1[MAX], m2[MAX], m3[MAX], i;
  printf("\n First Vector:\t");

#pragma omp parallel for
  for (i = 0; i < MAX; i++) {
    m1[i] = rand() % 1000;
  }
  for (i = 0; i < MAX; i++) {
    printf("%d\t", m1[i]);
  }
  printf("\n Second Vector:\t");
#pragma omp parallel for
  for (i = 0; i < MAX; i++) {
    m2[i] = rand() % 1000;
  }
  for (i = 0; i < MAX; i++) {
    printf("%d\t", m2[i]);
  }
  printf("\n Parallel-vector Addition:(m1,m2,m3)\t");
#pragma omp parallel for
  for (i = 0; i < MAX; i++) {
    m3[i] = m1[i] + m2[i];
  }
  for (i = 0; i < MAX; i++) {
    printf("\n%d\t%d\t%d", m1[i], m2[i], m3[i]);
  }
}


#include <bits/stdc++.h>
using namespace std;

int bestFit(vector<int> v, int n, int capacity) {
  int res = 0;
  int slotremain[n];
  for (int i = 0; i < n; i++) {
    int j;
    int min = capacity + 1;
    int count = 0;
    for (j = 0; j < res; j++) {
      if (slotremain[j] >= v[i] && slotremain[j] - v[i] < min) {
        count = j;
        min = slotremain[j] - v[i];
      }
    }
    if (min == capacity + 1) {
      slotremain[res] = capacity - v[i];
      res++;
    } else
      slotremain[count] -= v[i];
  }
  return res;
}

int main() {
  vector<int> v{60, 10, 40, 80};
  cout << bestFit(v, v.size(), 100);
  return 0;
}

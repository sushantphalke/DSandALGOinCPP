
#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
  int plat_needed = 1, result = 1;

  for (int i = 0; i < n; i++) {
    plat_needed = 1;
    
    for (int j = 0; j < n; j++) {
      if (i != j)
        if (arr[i] >= arr[j] && dep[j] >= arr[i])
          plat_needed++;
    }
    result = max(plat_needed, result);
  }
  return result;
}

int main() {
  int arr[] = {850, 890, 900, 1050, 1450, 1750};
  int dep[] = {860, 1150, 1070, 1080, 1850, 1950};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << findPlatform(arr, dep, n);
  return 0;
}

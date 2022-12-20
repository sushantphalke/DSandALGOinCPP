#include <bits/stdc++.h>
using namespace std;

int main() {
  //
  int k = 3;
  int n = 17;
  int partsize = n / k;
  int partadjust = n % k;

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < partsize + (i < partadjust); j++) {
      cout << j+1 << "_";
    }
    cout << endl;
  }

  return 0;
}
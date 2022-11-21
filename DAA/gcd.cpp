#include <bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2) {
  while (n1 != n2) {
    if (n1 > n2) {
      n1 = n1 - n2;
    } else {
      n2 = n2 - n1;
    }
  }
  return n1;
}

// int gcd(int n1, int n2) {
//     int n;
//   if (n1 > n2)
//     n = n2;
//   else
//     n = n1;
//   for (int i = n; i >= 1; i--) {
//     if (n2 % i == 0 and n1 % i == 0) {
//       return i;
//     }
//   }
//   return 1;
// }
int main() {
  int n1 = 42, n2 = 49;
  cout << gcd(n1, n2);
  return 0;
}
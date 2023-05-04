// Fib rec
// #include <iostream>
// using namespace std;

// void printFibonacci(int n) {
//   static int n1 = 0, n2 = 1, n3;
//   if (n > 0) {
//     n3 = n1 + n2;
//     n1 = n2;
//     n2 = n3;
//     cout << n3 << " ";
//     printFibonacci(n - 1);
//   }
// }
// int main() {
//   int n;
//   cout << "Enter the number of elements: ";
//   cin >> n;
//   cout << "Fibonacci Series: ";
//   cout << "0 "
//        << "1 ";
//   printFibonacci(n - 2);
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void fib(vector<int>& v, int n) {
  if (n <= 1) return;
  v.push_back(v.back() + v[v.size() - 2]);
  fib(v, n - 1);
}

int main() {
  int n;
  cout << "Enter number: ";
  cin >> n;
  vector<int> v;
  v.push_back(0);
  v.push_back(1);
  fib(v, n);
  for (auto p : v) {
    cout << p << " ";
  }
  return 0;
}
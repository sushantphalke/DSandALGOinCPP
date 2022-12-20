#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Enter number :";
  cin >> n;
  if (n % 31 == 0 && n % 41 == 0) {
    cout << "Foo Bar";
  }
  if (n % 31 == 0 && n % 41 != 0) {
    cout << "Foo";
  }
  if (n % 31 != 0 && n % 41 == 0) {
    cout << "Bar";
  } else {
    cout << " Entered Number is not divisible by both 31 and 41";
  }
  return 0;
}

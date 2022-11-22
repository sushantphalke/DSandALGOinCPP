// Fact itr
#include <iostream>
using namespace std;

long long factorial(int n) {
  if (n == 0) return 1;
  long long fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = fact * i;
  }
  return fact;
}

int main() {
  int n;

  cout << "Enter a positive integer: ";
  cin >> n;

  cout << "Factorial of " << n << " = " << factorial(n) << endl;

  //   cout<<INT16_MAX<<"__"<<INT64_MAX<<endl;

  return 0;
}

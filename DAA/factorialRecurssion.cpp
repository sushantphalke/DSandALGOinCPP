// fact rec
#include <iostream>
using namespace std;

long long factorial(int n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}

int main() {
  int n;

  cout << "Enter a positive integer: ";
  cin >> n;

  cout << "Factorial of " << n << " = " << factorial(n)<<endl;

    //   cout<<INT16_MAX<<"__"<<INT64_MAX<<endl;


  return 0;



}


+
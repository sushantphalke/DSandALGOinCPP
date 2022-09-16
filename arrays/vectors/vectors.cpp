#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> vec1;
  int element;
  for (int i = 0; i < 5; i++) {
    cout << "Enter an element to add on this vector :";
    cin >> element;
    vec1.push_back(element);
  }
  for (int i = 0; i < (vec1.size()); i++)
  {
    cout<<vec1[i];
  }
  

  return 0;
}
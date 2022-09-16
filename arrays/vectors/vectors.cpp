#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << ",";
  }
}

int main() {
  vector<int> vec1;
  int element;
  for (int i = 0; i < 5; i++) {
    cout << "Enter an element to add on this vector :";
    cin >> element;
    vec1.push_back(element);
  }

  printVector(vec1);
  vec1.pop_back();
  cout << "---------------";
  printVector(vec1);
  cout << "---------------";
  vec1[2] = 9;
  printVector(vec1);
  cout << "---------------";

  vector<int>::iterator iter = vec1.begin();
  vec1.insert(iter, 34, 33);
  printVector(vec1);
  cout << "---------------";

  return 0;
}
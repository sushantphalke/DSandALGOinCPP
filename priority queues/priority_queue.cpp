#include <bits/stdc++.h>
using namespace std;

int main() {
  priority_queue<int> s;
  cout << " gretest element on top of priority queue : " << endl;

  s.push(5);
  s.push(10);
  s.push(9);
  s.push(3);
  s.push(4);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    cout << s.top() << "_" << endl;
    s.pop();
  }

  cout << " samllset element on top of priority queue : " << endl;

  priority_queue<int, vector<int>, greater<int>> v;
  v.push(5);
  v.push(10);
  v.push(9);
  v.push(3);
  v.push(4);
  int p = v.size();
  for (int i = 0; i < p; i++) {
    cout << v.top() << "_" << endl;
    v.pop();
  }

  return 0;
}
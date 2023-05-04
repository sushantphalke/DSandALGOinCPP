#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  vector<vector<int>> v;
  vector<string> str;
  for (int i = 0; i < s; i++) {
    vector<int> p;
    int p1, p2;
    cin >> p1;
    p.push_back(p1);
    cin >> p2;
    p.push_back(p2);
    v.push_back(p);
  }
  int counter = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    counter = counter + (max(v[i][0], v[i + 1][0]) - min(v[i][0], v[i + 1][0]));
  }
  for (int i = 0; i < v.size()-1; i++) {
    counter = counter + (max(v[i][1], v[i + 1][1]) - min(v[i][1], v[i + 1][1]));
  }

  cout << "counter"<<counter<<":";


  return 0;
}
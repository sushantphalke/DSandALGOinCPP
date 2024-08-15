#include <bits/stdc++.h>
using namespace std;

int days(vector<int> v) {
  int N = v.size();
  stack<pair<int, int>> s;
  s.push({0, -1});
  int countdays = -1;
  for (int i = 1; i < N; i++) {
    int currday = 1;
    while (!s.empty()) {
      if (v[s.top().first] >= v[i]) {
        currday = max(currday, s.top().second + 1);
        s.pop();
      } 
      else break;
    }
    if (s.empty()) currday = -1;
    countdays = max(countdays, currday);
    s.push({i, currday});
  }

  if (countdays < 0)
    return 0;
  else
    return countdays;
}

int main() {
  //   vector<int> v = {6, 5, 8, 4, 7, 10, 9};
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  cout << days(v);
  return 0;
}
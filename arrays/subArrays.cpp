#include <bits/stdc++.h>
using namespace std;

double median(vector<int> v) {
  sort(v.begin(), v.end());
  int n =v.size() ;
  if (n% 2 != 0) {
    return (double)v[n / 2];
  }
  return (double)(v[(n - 1) / 2] + v[n / 2]) / 2.0;
}

void findSubArrays(vector<int> nums) {
  int n = nums.size();
  vector<vector<int>> v;
  for (int i = 0; i < n; i++) {
    vector<int> s;
    s.push_back(nums[i]);
    v.push_back(s);
    for (int j = i + 1; j < n; j++) {
      s.push_back(nums[j]);
      v.push_back(s);
    }
  }
  for (auto s : v) {

    cout << "[";
    for (auto p : s) {
      cout << p << ",";
    }
    cout << ']' <<"median="<<median(s)<<endl;

    
  }
}

int main() {
  vector<int> nums = {3, 2, 1, 4, 5};
  findSubArrays(nums);
  return 0;
}
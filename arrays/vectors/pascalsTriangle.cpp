#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0) return {};  // if number of rows are zero then return

    vector<vector<int>> result{{1}};  // delclare a multidiamentional array
    cout << result[1][1];

    for (int i = 1; i < numRows; ++i) {
      vector<int> temp{1};  // temprary array to store last element of result array
      for (int j = 0; j < result.back().size() - 1; ++j) {
        temp.push_back(result.back()[j] + result.back()[j + 1]);  // insert elements in an array by multidiamentional method
      }
      temp.push_back(1);       // insrert last element
      result.push_back(temp);  // insert temp array in result
    }
    cout << result[1][1];
    return result;
  }
};
int main() {
  generate(5);
  return 0;
}
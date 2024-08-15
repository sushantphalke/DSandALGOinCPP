// #include <bits/stdc++.h>
// using namespace std;

// void SubseqSumEqualtoK(int ind, int sum, vector<int>& ds, vector<int>& arr, int n, int K) {
//   if (ind == n) {
//     if (sum == K) {
//       for (auto s : ds) cout << s << " ";
//       cout << endl;
//     }
//   }
//   if (ind >= n) return;
//   ds.push_back(arr[ind]);
//   sum += arr[ind];
//   SubseqSumEqualtoK(ind + 1, sum, ds, arr, n, K);
//   sum -= arr[ind];
//   ds.pop_back();
//   SubseqSumEqualtoK(ind + 1, sum, ds, arr, n, K);
// }

// int main() {
//   vector<int> arr = {3, 1, 2, 1};
//   vector<int> ds;
//   int K = 3;
//   int sum = 0;
//   SubseqSumEqualtoK(0, 0, ds, arr, arr.size(), K);
//   return 0;
// }

// first answer found

#include <bits/stdc++.h>
using namespace std;

bool SubseqSumEqualtoK(int ind, int sum, vector<int>& ds, vector<int>& arr, int n, int K) {
  if (ind == n) {
    if (sum == K) {
      for (auto s : ds) cout << s << " ";
      cout << endl;
      return true;
    } else
      return false;
  }
  ds.push_back(arr[ind]);
  sum += arr[ind];
  if (SubseqSumEqualtoK(ind + 1, sum, ds, arr, n, K) == true) return true;
  sum -= arr[ind];
  ds.pop_back();
  if (SubseqSumEqualtoK(ind + 1, sum, ds, arr, n, K) == true) return true;
  return false;
}

int main() {
  vector<int> arr = {1, 2, 1};
  vector<int> ds;
  int K = 3;
  int sum = 0;
  SubseqSumEqualtoK(0, 0, ds, arr, arr.size(), K);
  return 0;
}

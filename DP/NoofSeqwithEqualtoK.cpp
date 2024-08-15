#include <bits/stdc++.h>
using namespace std;

int NoofseqwithEqualtoK(int ind, int sum, vector<int> arr, int n, int K) {
  if (ind >= n) {
    if (sum == K) {
      return 1;
    } else
      return 0;
  }
  sum += arr[ind];
  int l = NoofseqwithEqualtoK(ind + 1, sum, arr, n, K);
  sum -= arr[ind];
  int r = NoofseqwithEqualtoK(ind + 1, sum, arr, n, K);
  return l + r;
}

int main() {
  vector<int> arr = {3, 1, 2, 1, 2};
  int K = 4;
  cout << "Number of sequences with equal elements to k is: ";
  cout << NoofseqwithEqualtoK(0, 0, arr, arr.size(), K);

  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int ans = 0;

// int NoofseqwithEqualtoK(int ind, int sum, vector<int> arr, int n, int K, int& ans) {
//   if (ind >= n) {
//     if (sum == K) {
//       ans++;
//       return ans;
//     } else
//       return ans;
//   }
//   sum += arr[ind];
//   NoofseqwithEqualtoK(ind + 1, sum, arr, n, K, ans);
//   sum -= arr[ind];
//   NoofseqwithEqualtoK(ind + 1, sum, arr, n, K, ans);
//   return ans;
// }

// int main() {
//   vector<int> arr = {3, 1, 2, 1, 2};
//   int K = 4;
//   int ans = 0;
//   cout << "Number of sequences with equal elements to k is: ";
//   NoofseqwithEqualtoK(0, 0, arr, arr.size(), K, ans);

//   cout << ans;

//   return 0;
// }
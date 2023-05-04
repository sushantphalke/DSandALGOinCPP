#include <bits/stdc++.h>
// using namespace std;
//  int main(){
//     int n1,n2,x;
//     cin>> n1>>n2>>x;
//     int first =x;
//     int second=0;
//     int i=0;

//     while(first>second){
//         i++;
//         first+=n1;
//         // cout<<endl<<first;cout<<"i"<<endl;
//         second+=n2;
//     }
//     cout<<i;
//     return i;

//  }

// #include <iostream>

// using namespace std;

// int largest_prime_divisor(int n) {
//   int i = 2;
//   while (i * i <= n) {
//     if (n % i == 0) {
//       n /= i;
//     } else {
//       i++;
//     }
//   }
//   return n;
// }

// int reduce_to_zero(int n) {
//   int count = 0;
//   while (n > 0) {
//     if (n == 1) {
//       n--;
//     } else {
//       n = largest_prime_divisor(n);
//     }
//     count++;
//   }
//   return count;
// }

// int main() {
//   int n;
//   cin >> n;
//   cout << reduce_to_zero(n) << endl;
//   return 0;
// }

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, INT_MAX);  // initialize dp array with INT_MAX
  dp[n] = 0;                       // base case

  for (int i = n; i >= 1; i--) {
    if (dp[i] != INT_MAX) {                   // if this number is reachable
      dp[i - 1] = min(dp[i - 1], dp[i] + 1);  // subtract 1
      for (int j = sqrt(i); j >= 2; j--) {    // replace by largest prime divisor
        if (i % j == 0 && is_prime(j)) {
          dp[i / j] = min(dp[i / j], dp[i] + 1);
          break;  // we found the largest prime divisor, no need to check further
        }
      }
    }
  }

  cout << dp[0] << endl;  // answer is the minimum number of steps to reduce N to 0

  return 0;
}

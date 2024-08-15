// #include <bits/stdc++.h>
// using namespace std;

// void dfs(vector<int>& weight, vector<int>& ds, int idx, int capacity, int& result) {
//   if (ds.size() >= result) {
//     return;
//   }
//   if (idx == weight.size()) {
//     result = ds.size();
//     return;
//   }
//   for (int i = 0; i < ds.size(); i++) {
//     if (ds[i] + weight[idx] <= capacity) {
//       ds[i] += weight[idx];
//       dfs(weight, ds, idx + 1, capacity, result);
//       ds[i] -= weight[idx];
//     }
//   }
//   ds.push_back(weight[idx]);
//   dfs(weight, ds, idx + 1, capacity, result);
//   ds.pop_back();
// }

// int minslot(vector<int>& weight, int capacity) {
//   vector<int> ds;
//   int result = weight.size();
//   dfs(weight, ds, 0, capacity, result);
//   return result;
// }

// int main() {
//   int n, W, k;
//   cin >> n >> W >> k;
//   vector<int> wts(n);
//   for(int i=0;i<n;i++) cin>>wts[i];
//   int result = minslot(wts, W);
//   cout << result * k << endl;
// }

#include <bits/stdc++.h>
using namespace std;

int minslot(vector<int>& weight, int capacity) {
  const int N = weight.size();
  const int INF = 1e9;
  vector<pair<int, int>> dp(1 << N, {INF, INF});
  dp[0] = {0, INF};
  for (int mask = 1; mask < (1 << N); ++mask) {
    pair<int, int> best = {INF, INF};
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        pair<int, int> cur = dp[mask ^ (1 << i)];
        if (cur.second + weight[i] > capacity) {
          cur = {cur.first + 1, weight[i]};
        } else
          cur.second += weight[i];
        best = min(best, cur);
      }
    }
    dp[mask] = best;
  }
  return dp[(1 << N) - 1].first;
}

int main() {
  int n, W, k;
  cin >> n >> W >> k;
  vector<int> wts(n);
  for (int i = 0; i < n; i++) cin >> wts[i];
  int result = minslot(wts, W);
  cout << result * k << endl;
}

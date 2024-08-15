#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, Z, k;
  cin >> n >> Z >> k;
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  sort(weight.begin(), weight.end(), greater<int>());
  int total_cost = 0;
  int curr_weight = 0;

  for (int i = 0; i < n; i++) {
    if (curr_weight + weight[i] <= Z) {
      curr_weight += weight[i];
    } else {
      total_cost += k;
      curr_weight = 0;
      i--;
    }
  }

  if (curr_weight > 0) total_cost += k;
  cout << total_cost << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 5;
  vector<int> f(n);
  f[0] = 0;
  f[1] = 1;

  for (int i = 2; i <= n; i++) {
    f[i] = (f[i - 1] + f[i - 2]);
  }
  cout << f[5] << endl;
  return 0;
}
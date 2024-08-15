#include <iostream>

using namespace std;

int max_stability(int n, int m) {
  if (m % 2 == 0) {
    return (n * m) / 2;
  } else {
    return ((m - 1) * n) / 2;
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;
    int result = max_stability(n, m);
    cout << result << endl;
  }

  return 0;
}

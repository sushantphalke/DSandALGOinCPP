#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cout << "Enter the length of ary : ";
  cin >> n;
  int a[n + 1];
  a[n] = -1;
  cout << "Enter the elements of ary : ";

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int mx = -1;

  if (n == 1) {
    cout << " record breaking days : 1 " << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > mx && a[i] > a[i + 1]) {
      ans++;
    }
    mx = max(mx, a[i]);
  }
  cout << "record breaking days : " << ans << endl;
  return 0;
}
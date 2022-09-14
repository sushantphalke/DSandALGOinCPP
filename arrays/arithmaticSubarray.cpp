#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 0;
  cout << "Enter the length of ary : ";
  cin >> n;
  int a[n];
  cout << "Enter the elements of ary : ";

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int pd = a[1] - a[0];
  int j = 2;
  int curr = 2;
  int mxSubarrylength = 2;
  int lastInd = 2;
  while (j < 7) {
    if (pd == a[j] - a[j - 1]) {
      curr++;

    } else {
      pd = a[j] - a[j - 1];
      curr = 2;
    }
    mxSubarrylength = max(mxSubarrylength, curr);
    j++;
  }
  cout << "max subary length: " << mxSubarrylength << endl;

  return 0;
}
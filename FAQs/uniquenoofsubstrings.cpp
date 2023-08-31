
#include <bits/stdc++.h>
using namespace std;

void findSubstringInWraproundString(string p) {
  int ans = 0;
  int curLen = 0;
  int arr[26] = {0};

  for (int i = 0; i < p.size(); i++) {
    int curr = p[i] - 'a';
    if (i > 0 && (p[i - 1] != ((curr + 26 - 1) % 26 + 'a'))) {
      curLen = 0;
    }

    curLen++;
    if (curLen > arr[curr]) {
      ans += (curLen - arr[curr]);
      arr[curr] = curLen;
    }
  }

  cout << ans;
}

int main() {
  string p = "yzyy";

  findSubstringInWraproundString(p);

  return 0;
}

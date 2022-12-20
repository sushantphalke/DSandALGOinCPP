#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v;
  cin >> s >> v;
  s = s + v;
  v = s - v;
  s = s - v;
  cout << "swappped numbers: s =" << s << ", v=" << v;
}
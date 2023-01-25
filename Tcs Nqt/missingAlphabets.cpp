#include <bits/stdc++.h>
using namespace std;

void s(string str) {
  set<char> st;
  for (auto i : str)
    if (i != ' ') st.insert(tolower(i));
  if (st.size() == 26)
    cout << 0 << endl;
  else {
    for (char a = 'a'; a <= 'z'; a++) {
      if (st.count(a) == 0) cout << a;
    }
    cout << endl;
  }
};
int main() {
  string str;
  cin >> str;
  s(str);
  return 0;
}
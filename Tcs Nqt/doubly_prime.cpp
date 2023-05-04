#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
vector<int> primeFactors(int n) {
  vector<int> v;
  for (int i = 2; i <n; i++) {
    if(n % i == 0 && isPrime(i)) {
      v.push_back(i);
    }
  }
  return v;
};

int main() {
  // public:
  map<int, vector<int>> mp;
  int n = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    vector<int> curr = primeFactors(i);
    // set<int> st(curr.begin(),curr.end());
    mp[i] = curr;
  }
  for (auto m : mp) {
    if( m.second.size() == 2) {
      cout<<m.first<<" ";
    }
    cout << endl;
  }
  return 0;
}
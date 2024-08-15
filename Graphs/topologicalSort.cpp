#include <bits/stdc++.h>
using namespace std;

int sumOfDependencies(vector<int> a[], int v) {
  int e{};
  while (v--) e += a[v].size();
  return e;
}

int main() {
  int V, E;
  cin >> V >> E;
  int u, v;
  vector<int> adj[V];

  for (int i = 0; i < E; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (auto x : adj) {
    // for (auto s : x) {
    cout << typeid(x).name() << "_";
    // }
    cout << endl;
  }
  int s = sumOfDependencies(adj, V);
  cout << s;
  return 0;
}
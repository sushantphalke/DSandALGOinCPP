// #include <bits/stdc++.h>
// using namespace std;

// class Graph {
//   int V;
//   map<int, bool> visited;
//   map<int, list<int>> adj;

//  public:
//   void addEdge(int v, int w);
//   void DFS(int s);
// };
// void Graph ::addEdge(int v, int w) {
//   adj[v].push_back(w);
// }
// void Graph::DFS(int s) {
//   visited[s] = true;
//   cout << s << " ";
//   for (auto i : adj[s]) {
//     if (!visited[i]) {
//       this->DFS(i);
//     }
//   }
// }

// int main() {
//   Graph g;
//   g.addEdge(0, 1);
//   g.addEdge(0, 2);
//   g.addEdge(0, 5);
//   g.addEdge(0, 7);
//   //   g.addEdge(1, 2);
//   g.addEdge(1, 3);
//   g.addEdge(3, 4);
//   g.addEdge(5, 6);
//   g.addEdge(7, 8);

//   g.DFS(0);
//   cout << endl;

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Graph {
 public:
  map<int, bool> visited;
  map<int, list<int>> adj;

  void addEdge(int v, int w);
  void DFS(int s);
  void DFS(vector<int>&, int s);
};
void Graph ::addEdge(int v, int w) {
  this->adj[v].push_back(w);
}
void Graph::DFS(int s) {
  this->visited[s] = true;
  cout << s << " ";
  for (auto it : this->adj[s]) {
    if (!visited[it]) {
      this->DFS(it);
    }
  }
}
void Graph::DFS(vector<int>& ans, int s) {
  this->visited[s] = true;
  ans.push_back(s);
  for (auto i : this->adj[s]) {
    if (!this->visited[i]) {
      this->DFS(ans, i);
    }
  }
}
int main() {
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 5);
  g.addEdge(0, 7);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(5, 6);
  g.addEdge(7, 8);
  vector<int> ans;
  g.DFS(ans, 0);
    for(auto i:ans){
    cout<<i<<" ";
  }
  return 0;
}
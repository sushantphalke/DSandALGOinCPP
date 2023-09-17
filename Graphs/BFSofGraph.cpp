#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  vector<list<int>> adj;

 public:
  Graph(int V);
  void addEdge(int v, int w);
  void BFS(int v);
  void BFS(vector<int>& v, int s);
};
Graph::Graph(int V) {
  this->V = V;
  adj.resize(V);
}
void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}
void Graph ::BFS(int s) {
  queue<int> q;
  vector<bool> visited(V, false);
  q.push(s);
  visited[s] = true;
  while (q.size()) {
    s = q.front();
    cout << s << "  ";
    q.pop();
    for (auto it : adj[s]) {
      if (!visited[it]) {
        q.push(it);
        visited[it] = true;
      }
    }
  }
}
void Graph::BFS(vector<int>& v, int s) {
  queue<int> q;
  q.push(s);
  v.push_back(s);
  vector<bool> visited(V, false);
  while (q.size()) {
    s = q.front();
    q.pop();
    for (auto node : adj[s]) {
      if (!visited[node]) {
        q.push(node);
        v.push_back(node);
        visited[node] = true;
      }
    }
  }
}
int main() {
  Graph g(9);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 5);
  g.addEdge(0, 7);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  g.addEdge(5, 6);
  g.addEdge(7, 8);

  g.BFS(0);
  cout << endl;

  vector<int> v;
  g.BFS(v, 0);
  for (auto s : v) cout << s << "_";

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Graph {
  int V;
  vector<list<int>> adj;

 public:
  Graph(int V);
  void addEdge(int v, int w);
  void BFS(int s);
};
Graph::Graph(int V) {
  this->V = V;
  adj.resize(V);
}
void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}
void Graph::BFS(int s) {
  queue<int> q;
  q.push(s);
  vector<bool> visited(V, false);
  while (q.size()) {
    s = q.front();
    cout << s << "  ";
    q.pop();
    for (auto node : adj[s]) {
      if (!visited[node]) {
        q.push(node);
        visited[node] = true;
      }
    }
  }
}
int main() {
  Graph g(9);
  g.addEdge(0, 1);  // A - B
  g.addEdge(0, 2);  // A- C
  g.addEdge(0, 5);   // B -C
  g.addEdge(0, 7);    // D - E
  g.addEdge(1, 2);  // B -C
  g.addEdge(1, 3);  // D - E
  g.addEdge(3, 4);  // D - E
  g.addEdge(5,6);
  g.addEdge(7,8);
  g.BFS(0);

  return 0;
}
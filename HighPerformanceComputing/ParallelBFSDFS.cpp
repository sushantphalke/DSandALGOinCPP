#include <bits/stdc++.h>
// included in bits/stdc++.h  #include <omp.h>

using namespace std;

void bfs(vector<vector<int>> adjList, int startNode) {
  queue<int> q;
  vector<bool> visited(adjList.size(), false);

  q.push(startNode);
  visited[startNode] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cout << node << " ";

#pragma omp parallel for
    for (int i = 0; i < adjList[node].size(); i++) {
      int neighbor = adjList[node][i];
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}
void dfs(vector<vector<int>> adjList, int startNode) {
  stack<int> s;
  vector<bool> visited(adjList.size(), false);

  s.push(startNode);

  while (!s.empty()) {
    int node = s.top();
    s.pop();

    if (!visited[node]) {
      visited[node] = true;
      cout << node << " ";

#pragma omp parallel for
      for (int i = 0; i < adjList[node].size(); i++) {
        int neighbor = adjList[node][i];
        if (!visited[neighbor]) {
          s.push(neighbor);
        }
      }
    }
  }
}
int main() {
  vector<vector<int>> adjList = {{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 5}, {2, 5}, {3, 4}};
  int startNode = 0;

  cout << "BFS traversal: ";
  bfs(adjList, startNode);
  cout << endl;
  cout << "DFS traversal: ";
  dfs(adjList, startNode);
  cout << endl;

  return 0;
}

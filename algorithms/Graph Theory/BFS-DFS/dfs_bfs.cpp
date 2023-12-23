#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int MAX_NODE = 1e5 + 9;
vector<int> graph[MAX_NODE]; // adjacency list
vector<bool> visit(MAX_NODE, false);

vector<int> bfs(int u) {
  vector<int> ans;
  queue<int> q;
  q.push(u);
  visit[u] = true;
  while (!q.empty()) {
    int top = q.front(); q.pop();
    ans.push_back(top);
    for (auto v : graph[top]) {
      if (!visit[v]) {
        q.push(v);
        visit[v] = true;
      }
    }
  }
  return ans;
}

vector<int> dfs(int u) {
  vector<int> ans;
  stack<int> st;
  st.push(u);
  visit[u] = true;
  while (!st.empty()) {
    int top = st.top(); st.pop();
    ans.push_back(top);
    for (auto v : graph[top]) {
      if (!visit[v]) {
        st.push(v);
        visit[v] = true;
      }
    }
  }
  return ans;
}


int main() {
  cout << "Enter graph input: ";
  int nodes, edges; cin >> nodes >> edges;
  for (int i = 1; i <= edges; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> bfs_ans = bfs(1);
  cout << "BFS Path: ";
  for (auto x : bfs_ans) {
    cout << x << ' ';
  }
  cout << '\n';


  for (int i = 0; i <= nodes; i++) {
    visit[i] = false;
  }

  vector<int> dfs_ans = dfs(1);
  cout << "DFS Path: ";
  for (auto x : dfs_ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}
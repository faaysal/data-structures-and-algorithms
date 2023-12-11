#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 1e9;
vector<pair<int, int>> g[N];
vector<bool> vis(N, false);
int dis[N];

int n, m;

void dijkstra(int u) {
  for (int i = 1; i <= n; i++) {
    dis[i] = inf;
  }
  dis[u] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({ 0, u });
  while (!pq.empty()) {
    int selected_node = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    if (vis[selected_node]) continue;
    vis[selected_node] = true;
    for (auto [v, w] : g[selected_node]) {
      if (dis[v] > (d + w)) {
        dis[v] = d + w;
        pq.push({ dis[v], v });
      }
    }
  }
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({ v,w });
    g[v].push_back({ u,w });
  }

  dijkstra(1);

  for (int u = 1; u <= n; u++) {
    cout << u << ": " << dis[u] << '\n';
  }

  return 0;
}

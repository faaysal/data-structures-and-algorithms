#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;
const ll inf = 1e18;
vector<pair<int, int>> g[N];
vector<bool> vis(N, false);
vector<ll> dis(N, inf);
int n, m;

void dijkstra(int u) {
  dis[u] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({ 0, u });
  while (!pq.empty()) {
    int selected_node = pq.top().second;
    ll d = pq.top().first;
    pq.pop();
    if (vis[selected_node]) continue;
    vis[selected_node] = true;
    for (auto [v, w] : g[selected_node]) {
      if (dis[v] > (1ll * d + w)) {
        dis[v] = 1ll * d + w;
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
  }

  dijkstra(1);

  for (int u = 1; u <= n; u++) {
    cout << dis[u] << ' ';
  }
  cout << '\n';

  return 0;
}
// https://cses.fi/problemset/task/1671/
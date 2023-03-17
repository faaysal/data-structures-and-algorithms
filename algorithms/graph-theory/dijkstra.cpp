#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long INF = 1e18;

int n, m;
int visited[N];
int parent[N];
long long d[N];
vector<pair<long long, int>> graph[N];

void dijkstra(int src)
{
    // initially INF distance
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    // src 0 distance
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        // take the lowest unvisited distance
        pair<long long, int> top = pq.top();
        pq.pop();

        long long distance = -top.first;
        int selected_node = top.second;

        if (visited[selected_node] == 1)
            continue;

        visited[selected_node] = 1;

        // explore lowest distance node and relaxation
        for (auto adj : graph[selected_node])
        {
            int adj_node = adj.first;
            int w = adj.second;
            if (d[adj_node] > distance + w)
            {
                d[adj_node] = distance + w;
                pq.push({-d[adj_node], adj_node});
                parent[adj_node] = selected_node;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1);
    // for (int i = 1; i < n; i++)
    // {
    //     cout << i << ": " << d[i] << endl;
    // }
    // cout << "Distance: " << d[n] << endl;

    if (d[n] == INF)
    {
        cout << "-1" << endl;
        return 0;
    }

    int par = n;
    vector<int> path;
    while (par != -1)
    {
        // cout << par << endl;
        path.push_back(par);
        par = parent[par];
    }

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
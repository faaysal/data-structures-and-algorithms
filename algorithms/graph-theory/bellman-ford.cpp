/* This code is work for Directed graph and No Negative Cycle graph */

#include <bits/stdc++.h>
using namespace std;

/*

4 4
0 1 10
1 2 -12
0 2 5
2 3 4

 */

int n, m;
const int INF = 1e9;
const int N = 1e5;
int d[N];
vector<pair<int, int>> graph[N];

void bellman_ford(int src)
{
    // "INFINITY" initial distance
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[src] = 0;

    // loop (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        // "relaxation" all edges
        for (int node = 0; node < m; node++)
        {
            for (auto adj : graph[node])
            {
                int u = node;
                int v = adj.first;
                int w = adj.second;
                if (d[u] + w < d[v])
                    d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    // cin >> n >> m;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     graph[u].push_back({v, w});
    // }

    n = 4, m = 4;
    graph[0].push_back({1, 10});
    graph[1].push_back({2, -12});
    graph[0].push_back({2, 5});
    graph[2].push_back({3, 4});

    bellman_ford(0);

    // print
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}
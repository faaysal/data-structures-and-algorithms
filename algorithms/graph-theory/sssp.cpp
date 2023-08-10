#include <bits/stdc++.h>
using namespace std;

// single source shortest path
// we can use dfs to get the shortest path of unweighted graph

/*

INPUT:
7 7
0 1
0 2
0 5
1 4
4 2
5 6
6 3



OUTPUT:   0 1 2 5 4 6 3 (Traversal-src-0)

Nodes:    0 1 2 3 4 5 6
Distance: 0 1 1 3 2 1 2
 */

vector<int> distance(1e5, 0);

void bfs(vector<int> graph[], int nodes, int source)
{
    queue<int> q;
    vector<bool> visited(nodes, false);

    q.push(source);
    visited[source] = true;
    ::distance[source] = 0;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto i : graph[top])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                ::distance[i] = ::distance[top] + 1;
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj_list[nodes];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs(adj_list, nodes, 0);

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> " << ::distance[i] << endl;
    }

    return 0;
}
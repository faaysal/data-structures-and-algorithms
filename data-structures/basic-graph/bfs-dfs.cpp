#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edgeWeightPair;

/* Read Notes to understand concept */

// Bi-Directional & Weighted Graph
class Graph
{
public:
    int V;
    list<edgeWeightPair> *adj; // dynamic array of list (using pointer)

    Graph(int v)
    {
        V = v;
        adj = new list<edgeWeightPair>[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printNeighbour(int n)
    {
        cout << n << " => ";
        for (auto i = adj[n].begin(); i != adj[n].end(); i++)
        {
            cout << "(" << i->first << ", " << i->second << ")";
        }
        cout << endl;
    }

    void BFS(int source)
    {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int v = q.front();
            cout << v << " ";
            q.pop();

            for (auto el : adj[v])
            {
                if (!visited[el.first])
                {
                    q.push(el.first);
                    visited[el.first] = true;
                }
            }
        }
    }

    void DFS(int source)
    {
        static vector<bool> visited(V, false);
        visited[source] = true;

        cout << source << " ";

        for (auto el : adj[source])
        {
            if (!visited[el.first])
            {
                DFS(el.first);
            }
        }
    }
};

/*
7 10
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4
5 4 6
2 5 8

 */

int main()
{
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    for (int i = 0; i < V; i++)
    {
        g.printNeighbour(i);
    }

    cout << "BFS: ";
    g.BFS(0);
    cout << endl;

    cout << "DFS: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
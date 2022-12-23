#include <bits/stdc++.h>
using namespace std;

/*

INPUT:
5 7
4 5
4 3
5 3
5 1
5 2
3 2
1 2



Output: 4 5 3 1 2


Time Complexity: O(V+E)
Space Complexity: O(V)


 */

void dfs(vector<int> adj_list[], int nodes, int src)
{
    vector<bool> visited(nodes, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        // get and print top
        int top = q.front();
        q.pop();
        cout << top << " ";

        // explore top
        for (auto i : adj_list[top])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    ++nodes;

    vector<int> adj_list[nodes];

    // getting input in adjacency list
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[v].push_back(u);
        adj_list[u].push_back(v);
    }

    dfs(adj_list, nodes, 4);

    return 0;
}

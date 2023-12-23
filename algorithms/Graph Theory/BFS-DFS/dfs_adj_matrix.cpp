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



Output: 4 3 2 1 5


Time Complexity: O(V^2)
Space Complexity: O(V^2)


 */

void dfs(int **matrix, int nodes, int src)
{
    static vector<bool> visited(nodes, false);

    cout << src << " ";
    visited[src] = true;

    for (int i = 0; i < nodes; i++)
    {
        if (matrix[src][i] == 1 && !visited[i])
        {
            dfs(matrix, nodes, i);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    ++nodes;

    // int *matrix[nodes];
    int **matrix = new int *[nodes];

    for (int i = 0; i < nodes; i++)
    {
        matrix[i] = new int[nodes];
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    dfs(matrix, nodes, 4);

    return 0;
}

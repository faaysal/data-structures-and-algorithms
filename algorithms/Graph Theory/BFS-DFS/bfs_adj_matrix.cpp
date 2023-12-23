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



Output: 4 3 5 2 1


Time Complexity: O(V^2)
Space Complexity: O(V^2)


 */

void bfs(int **matrix, int nodes, int src)
{

    vector<bool> visited(nodes, false);

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        cout << top << " ";

        for (int i = 0; i < nodes; i++)
        {
            if (matrix[top][i] == 1 && !visited[i])
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

    bfs(matrix, nodes, 4);

    return 0;
}

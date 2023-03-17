#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e3 + 5;
int matrix[N][N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    return 0;
}
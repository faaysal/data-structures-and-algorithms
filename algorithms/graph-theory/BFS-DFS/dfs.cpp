#include <bits/stdc++.h>
using namespace std;

/*
USING RECURSION
---------------
INPUT:
7 6
1 2
2 3
2 4
2 5
1 6
1 7

Output: 1 2 3 4 5 6 7 (Recusive) -> src(1)

Time Complexity: O(V+E)
Space Complexity: O(V)

USING STACK
-----------
INPUT:
5 5
1 0
0 2
2 1
0 3
1 4

Output: 0 3 2 1 4 (Stack) -> src(0)

Time Complexity: O(V+E)
Space Complexity: O(V)

 */

/*
// using recursion
void dfs(vector<int> adj_list[], int nodes, int src)
{
    static vector<bool> visited(nodes, false);
    visited[src] = true;

    cout << src << " ";

    // explore src
    for (auto i : adj_list[src])
    {
        if (!visited[i])
        {
            dfs(adj_list, nodes, i);
        }
    }
}
*/

// using stack
void dfs(vector<int> adj_list[], int nodes, int src)
{
    vector<bool> visited(nodes, false);
    visited[src] = true;
    stack<int> st;

    st.push(src);
    visited[src] = 1;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        cout << top << " ";

        for (auto i : adj_list[top])
        {
            if (!visited[i])
            {
                st.push(i);
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

    dfs(adj_list, nodes, 0);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*

0---->1
     / \
    /   \
   2-----3


Time Complexity: O(n^2)
Space Complexity: O(n^2)

 */

int main()
{
    int nodes = 4;

    // list of edge
    // Space: O(E) -> O(n^2){worst case}
    vector<vector<int>> edge_list = {{0, 1}, {1, 0}, {1, 2}, {2, 1}, {1, 3}, {3, 1}, {2, 3}, {3, 2}};

    for (int i = 0; i < edge_list.size(); i++)
    {
        cout << edge_list[i][0] << "->" << edge_list[i][1] << endl;
    }

    return 0;
}

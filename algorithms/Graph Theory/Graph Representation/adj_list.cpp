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

    // Space: O(n)
    vector<int> adj_list[nodes];

    // Time: O(E) -> O(n^2)
    // Space: O(n^2)
    adj_list[0].push_back(1);
    adj_list[1].push_back(0);
    adj_list[1].push_back(2);
    adj_list[1].push_back(3);
    adj_list[2].push_back(1);
    adj_list[2].push_back(3);
    adj_list[3].push_back(1);
    adj_list[3].push_back(2);

    // Time: O(n^2)
    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

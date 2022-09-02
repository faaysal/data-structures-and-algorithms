#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = right = NULL;
    }
};

// print space levelwise
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}

// print tree
/*

Root: 0
Left:
    Root: 1
    Left: 3
    Right: 4
Right:
    Root: 2
    Left:
        Root: 5
        Left: 7
        Right: 8
    Right: 6

 */

void printTree(Node *root, int level)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL && level != 0)
    {
        cout << root->value << endl;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->value << endl;
    }

    if (root->left)
    {
        spacePrint(level);
        cout << "Left: ";
        printTree(root->left, level + 1);
    }

    if (root->right)
    {
        spacePrint(level);
        cout << "Right: ";
        printTree(root->right, level + 1);
    }
}

void getLeafNodesVal(Node *root, string &str)
{
    if (root->left)
        getLeafNodesVal(root->left, str);

    if (root->right)
        getLeafNodesVal(root->right, str);

    if (root->left == NULL && root->right == NULL)
        str += (root->value + '0');
}

void getNonLeafLeftNodesVal(Node *root, string &str)
{
    if (root->left == NULL && root->right == NULL)
        return;

    else if (root->left)
    {
        str += (root->value + '0');
        getNonLeafLeftNodesVal(root->left, str);
    }

    else if (root->right)
    {
        str += (root->value + '0');
        getNonLeafLeftNodesVal(root->right, str);
    }
}

void getNonLeafRightNodesVal(Node *root, string &str)
{
    if (root->left == NULL && root->right == NULL)
        return;

    else if (root->right)
    {
        str += (root->value + '0');
        getNonLeafRightNodesVal(root->right, str);
    }

    else if (root->left)
    {
        str += (root->value + '0');
        getNonLeafRightNodesVal(root->left, str);
    }
}

void boundaryTraversal(Node *root, string &str)
{
    // step 1: root
    str += (root->value + '0');

    // step 2: left nodes (non leaf)
    string leftNodesNonLeaf = "";
    getNonLeafLeftNodesVal(root->left, leftNodesNonLeaf);
    str += leftNodesNonLeaf;
    cout << "Left: " << leftNodesNonLeaf << endl;

    // step 3: all leaf nodes
    string allLeafNodesVal;
    getLeafNodesVal(root, allLeafNodesVal);
    str += allLeafNodesVal;
    cout << "Leaf: " << allLeafNodesVal << endl;

    // step 4: right nodes (non leaf) reverse way
    string rightNodesNonLeaf = "";
    getNonLeafRightNodesVal(root->right, rightNodesNonLeaf);
    reverse(rightNodesNonLeaf.begin(), rightNodesNonLeaf.end());
    str += rightNodesNonLeaf;
    cout << "Right: " << rightNodesNonLeaf << endl;
}

/* input
5
0 1 3
1 -1 2
2 -1 -1
3 4 -1
4 -1 -1

=> 01243

9
0 1 4
1 -1 2
2 3 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1

=> 01236784

10
0 1 4
1 -1 2
2 3 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 9
9 -1 -1

=> 012367984
 */

int main()
{
    int n;
    cin >> n;

    Node *allNodes[n];

    for (int i = 0; i < n; i++)
    {
        allNodes[i] = new Node(-1);
    }

    for (int i = 0; i < n; i++)
    {
        int val, left, right;
        cin >> val >> left >> right;

        allNodes[i]->value = val;
        if (left != -1)
            allNodes[i]->left = allNodes[left];

        if (right != -1)
            allNodes[i]->right = allNodes[right];
    }

    printTree(allNodes[0], 0);

    string boundaryTraversalRes = "";
    boundaryTraversal(allNodes[0], boundaryTraversalRes);
    cout << "Boundary Traversal: " << boundaryTraversalRes << endl;

    return 0;
}
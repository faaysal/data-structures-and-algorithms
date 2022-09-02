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

// 314075826 (Left Root Rights)
void inorder(Node *root, string &str)
{
    if (root == NULL)
        return;

    inorder(root->left, str);
    str += (root->value + '0');
    inorder(root->right, str);
}

// 013425786 (Root Left Right)
void preorder(Node *root, string &str)
{
    if (root == NULL)
        return;

    str += (root->value + '0');
    preorder(root->left, str);
    preorder(root->right, str);
}

// 341785620 (Left Right Root)
void postorder(Node *root, string &str)
{
    if (root == NULL)
        return;

    postorder(root->left, str);
    postorder(root->right, str);
    str += (root->value + '0');
}

// 012345678 (level order traversing)
void levelorder(Node *root, string &str)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    int level = 0;

    int max = INT32_MIN;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front != NULL)
        {
            if (level == 3)
            {
                if (max < front->value)
                {
                    max = front->value;
                }
            }

            str += (front->value + '0');
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    cout << "Max at level 3: " << max << endl;
}

/* input
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
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
    string inorderRes;
    inorder(allNodes[0], inorderRes);
    cout << "Inorder: " << inorderRes << endl;

    string preorderRes;
    preorder(allNodes[0], preorderRes);
    cout << "Preorder: " << preorderRes << endl;

    string postorderRes;
    postorder(allNodes[0], postorderRes);
    cout << "Preorder: " << postorderRes << endl;

    string leveloderRes;
    levelorder(allNodes[0], leveloderRes);
    cout << "Level Order: " << leveloderRes << endl;

    return 0;
}
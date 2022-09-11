#include <bits/stdc++.h>

using namespace std;

// tree node structure
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

// space print for print tree
void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
}

// print tree
void printTree(TreeNode *root, int level)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL && level != 0)
    {
        cout << root->val << endl;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root: " << root->val << endl;
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

// insert at bst
TreeNode *insertAtBST(TreeNode *root, int val)
{
    TreeNode *newNode = new TreeNode(val);

    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (root->val > val)
    {
        root->left = insertAtBST(root->left, val);
    }

    if (root->val < val)
    {
        root->right = insertAtBST(root->right, val);
    }

    return root;
}

// concat two vector
vector<int> concat(vector<int> v1, vector<int> v2)
{
    vector<int> v;

    for (int i = 0; i < v1.size(); i++)
        v.push_back(v1[i]);

    for (int i = 0; i < v2.size(); i++)
        v.push_back(v2[i]);

    return v;
}

// inorder traversal
vector<int> inorder(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
        return v;

    v = concat(v, inorder(root->left));
    v.push_back(root->val);
    v = concat(v, inorder(root->right));

    return v;
}

// print vector
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';

    cout << endl;
}

// search in bst
TreeNode *search(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    if (val < root->val)
        return search(root->left, val);

    return search(root->right, val);
}

// get path of a node
string getPath(TreeNode *root, int val)
{
    string str = "";

    if (root == NULL)
        return str;

    if (root->val == val)
        return to_string(root->val) + " ";

    if (val < root->val)
    {
        str += to_string(root->val) + " -> ";
        str += getPath(root->left, val);
    }

    if (val > root->val)
    {
        str += to_string(root->val) + " -> ";
        str += getPath(root->right, val);
    }

    return str;
}

// get inorder successor of a node
TreeNode *getInOrderSuccessor(TreeNode *root)
{
    while (root->left)
        root = root->left;

    return root;
}

// delete a node
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->val == key)
    {
        if (!(root->left))
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        else if (!(root->right))
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        else
        {
            TreeNode *inorderSuccessor = getInOrderSuccessor(root->right);
            root->val = inorderSuccessor->val;
            root->right = deleteNode(root->right, inorderSuccessor->val);
        }
    }

    else if (key > root->val)
        root->right = deleteNode(root->right, key);

    else if (key < root->val)
        root->left = deleteNode(root->left, key);

    return root;
}

/*
input:
10
11 5 9 43 34 1 2 7 8 21
 */

int main()
{
    TreeNode *root = NULL;

    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insertAtBST(root, val);
    }

    vector<int> v = inorder(root);
    print(v);
    printTree(root, 0);

    cout << "Search a val : ";
    cin >> val;
    TreeNode *searchedNode = search(root, val);
    string path = getPath(root, val);

    searchedNode ? cout << "Found: " << searchedNode->val << endl : cout << "Can't Found\n";
    cout << "Path: " << path << endl;

    root = deleteNode(root, val);
    v = inorder(root);
    print(v);
    printTree(root, 0);

    return 0;
}
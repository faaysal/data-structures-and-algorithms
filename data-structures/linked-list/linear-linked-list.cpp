#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

// display all node
void display(Node *&head)
{
    Node *node = head;
    while (node != NULL)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

// get length
int getLength(Node *&head)
{
    Node *node = head;
    int count = 0;
    while (node != NULL)
    {
        count++;
        node = node->next;
    }

    return count;
}

// insert at head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// insert at tail
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }

    node->next = newNode;
}

// insert at specific index
void insertAtSpecificIndex(Node *&head, int index, int val)
{
    if (index > getLength(head) && index < 0)
        return;

    if (index == 0)
    {
        insertAtHead(head, val);
        return;
    }

    Node *node = head;
    for (int i = 0; i < index - 1; i++)
        node = node->next;

    Node *newNode = new Node(val);
    newNode->next = node->next;
    node->next = newNode;
}

// search value (if linked list have duplicate then we return the first value)
int searchValue(Node *&head, int val)
{
    if (head == NULL)
        return -1;

    Node *node = head;

    bool isFound = false;
    int index = 0;

    while (node != NULL)
    {
        if (node->value == val)
        {
            isFound = true;
            break;
        }

        node = node->next;
        index++;
    }

    return isFound ? index : -1;
}

// search value (we return the array of founded indexes, first index is how many time we found this value)
int *searchValueInDuplicateLinkedList(Node *&head, int val)
{
    int len = getLength(head);
    int *founded_indexes = new int[len + 1];

    Node *node = head;
    int index, top;
    index = 0;
    top = 1;

    while (node != NULL)
    {
        if (node->value == val)
        {
            founded_indexes[top] = index;
            top++;
        }

        node = node->next;
        index++;
    }

    founded_indexes = (int *)realloc(founded_indexes, sizeof(int) * top);
    founded_indexes[0] = --top;

    return founded_indexes;
}

// insert after specific value
void insertAfterSpecificValue(Node *&head, int val, int insertValue)
{
    int index = searchValue(head, val);
    if (index == -1)
        return;

    insertAtSpecificIndex(head, index + 1, insertValue);
}

// insert after all specific value
void insertAfterAllSpecificValue(Node *&head, int val, int insertValue)
{
    int *founded_indexes = searchValueInDuplicateLinkedList(head, val);
    if (founded_indexes[0] == 0)
        return;

    int addedCount = 0;
    for (int i = 1; i <= founded_indexes[0]; i++)
    {
        insertAtSpecificIndex(head, founded_indexes[i] + 1 + addedCount, insertValue);
        addedCount++;
    }
}

// delete at head
void deleteAtHead(Node *&head)
{
    if (head == NULL)
        return;

    Node *delNode = head;
    head = delNode->next;
    delete delNode;
}

// delete at tail
void deleteAtTail(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *node = head;
    while (node->next->next != NULL)
    {
        node = node->next;
    }

    Node *delNode = node->next;
    delete delNode;
    node->next = NULL;
}

// delete at specific index
void deleteAtSpecificIndex(Node *&head, int index)
{
    if (index >= getLength(head) || index < 0)
        return;

    if (head == NULL)
        return;

    if (index == 0)
    {
        deleteAtHead(head);
        return;
    }

    Node *node = head;
    for (int i = 0; i < index - 1; i++)
        node = node->next;

    Node *delNode = node->next;
    node->next = delNode->next;
    delete delNode;
}

// delete specific value
void deleteSpecificValue(Node *&head, int val)
{
    int index = searchValue(head, val);

    if (index == -1)
        return;

    deleteAtSpecificIndex(head, index);
}

// delete all specific value
void deleteAllSpecificValue(Node *&head, int val)
{
    int *founded_indexes = searchValueInDuplicateLinkedList(head, val);
    if (founded_indexes[0] == 0)
        return;

    int deletedCount = 0;
    for (int i = 1; i <= founded_indexes[0]; i++)
    {
        deleteAtSpecificIndex(head, founded_indexes[i] - deletedCount);
        deletedCount++;
    }
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 15);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    insertAtTail(head, 115);
    insertAtTail(head, 5);
    insertAtSpecificIndex(head, 0, 0);
    insertAtSpecificIndex(head, 1, 0);
    insertAtSpecificIndex(head, 6, 0);
    insertAfterSpecificValue(head, 5, 50);
    insertAfterAllSpecificValue(head, 0, 100);
    deleteAtHead(head);
    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtSpecificIndex(head, 0);
    deleteAtSpecificIndex(head, getLength(head) - 1);
    insertAtHead(head, 21);
    insertAtTail(head, 21);
    insertAtSpecificIndex(head, 5, 21);
    deleteSpecificValue(head, 5);
    deleteSpecificValue(head, 50);
    deleteAllSpecificValue(head, 21);

    display(head);
    cout << "Length: " << getLength(head) << endl;
    cout << "Index: " << searchValue(head, 5) << endl;

    int *founded_indexes = searchValueInDuplicateLinkedList(head, 5);
    if (founded_indexes[0] == 0)
        cout << "Not Found\n";
    else
    {
        cout << "Founded Indexes: ";
        for (int i = 1; i <= founded_indexes[0]; i++)
        {
            cout << founded_indexes[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
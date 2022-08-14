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

void display(Node *&head)
{
    if (head == NULL)
        return;

    Node *node = head;

    do
    {
        cout << node->value << " ";
        node = node->next;
    } while (node != head);
    cout << endl;
}

int length(Node *&head)
{
    if (head == NULL)
        return 0;

    Node *node = head;

    int count = 0;
    do
    {
        node = node->next;
        count++;
    } while (node != head);

    return count;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node *lastNode = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    newNode->next = head;
    head = newNode;
    lastNode->next = head;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }

    Node *lastNode = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->next = head;
}

void deleteAtHead(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *delNode = head;
    Node *lastNode = head;
    while (lastNode->next != head)
    {
        lastNode = lastNode->next;
    }

    head = delNode->next;
    lastNode->next = head;
    delete delNode;
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *prevLastNode = head;
    while (prevLastNode->next->next != head)
    {
        prevLastNode = prevLastNode->next;
    }
    Node *delNode = prevLastNode->next;
    prevLastNode->next = head;
    delete delNode;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 150);
    insertAtTail(head, 250);
    insertAtHead(head, 100);

    deleteAtTail(head);
    deleteAtTail(head);
    deleteAtHead(head);

    display(head);
    cout << "Length: " << length(head) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
private:
    int lengthCount;

public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        lengthCount = 0;
    }

    /* linked list methods */

    // get length
    int length()
    {
        return this->lengthCount;
    }

    // display list
    void display()
    {
        Node *node = this->head;
        while (node != NULL)
        {
            cout << node->value;
            if (node->next != NULL)
                cout << " -> ";
            node = node->next;
        }
        cout << endl;
    }

    // insertion at head
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (this->head == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
            this->lengthCount++;
            return;
        }

        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;

        this->lengthCount++;
    }

    // insertion at tail
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (this->head == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
            this->lengthCount++;
            return;
        }

        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
        this->lengthCount++;
    }

    // find mid
    Node *findMid()
    {
        Node *fast, *slow;
        fast = this->head;
        slow = this->head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main()
{
    LinkedList myList;
    int n, val;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        myList.insertAtTail(val);
    }

    myList.display();
    Node *mid = myList.findMid();
    if (mid != NULL)
    {
        cout << "Mid: " << mid->value << endl;
    }

    return 0;
}
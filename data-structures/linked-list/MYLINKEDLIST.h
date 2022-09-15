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

class MyLinkedList
{
    Node *head;
    Node *tail;
    int length;

public:
    MyLinkedList()
    {
        head = tail = NULL;
        length = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= length)
            return -1;

        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp->value;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        length++;

        if (length == 1)
            tail = head;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (length == 0)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > length)
            return;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        if (index == length)
        {
            addAtTail(val);
            return;
        }

        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }

    void deleteAtHead()
    {
        if (head == NULL)
            return;

        Node *delNode = head;

        if (length == 0)
            head = tail = NULL;
        else
            head = head->next;

        length--;
        delete delNode;
    }

    void deleteAtTail()
    {
        if (head == NULL)
            return;

        Node *delNode = tail;

        if (length == 0)
            head = tail = NULL;
        else
        {
            Node *temp = head;
            while (temp->next != delNode)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
        }

        length--;
        delete delNode;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;

        if (index == 0)
        {
            deleteAtHead();
            return;
        }

        if (index == length - 1)
        {
            deleteAtTail();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node *delNode = temp->next;
        temp->next = delNode->next;

        length--;
        delete delNode;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node<T> *next;

    Node(T val)
    {
        value = val;
        next = NULL;
    }
};

template <class T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    Queue()
    {
        head = tail = NULL;
        length = 0;
    }

    /* queue methods */

    // enqueue
    void enqueue(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (length == 0)
        {
            head = tail = newNode;
            length++;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        length++;
    }

    // dequeue
    T dequeue()
    {
        if (length == 0)
        {
            T garbage;
            return garbage;
        }

        Node<T> *delNode = head;
        T returnValue = delNode->value;

        if (length == 1)
            head = tail = NULL;
        else
            head = head->next;

        delete delNode;
        length--;
        return returnValue;
    }

    // front
    T front()
    {
        if (length == 0)
        {
            T garbage;
            return garbage;
        }

        return head->value;
    }

    T back()
    {
        if (length == 0)
        {
            T garbage;
            return garbage;
        }

        return tail->value;
    }

    // size
    int size()
    {
        return length;
    }

    // empty
    bool empty()
    {
        return !length;
    }
};
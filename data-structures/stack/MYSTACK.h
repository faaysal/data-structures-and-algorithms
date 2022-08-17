#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node<T> *prev;
    Node<T> *next;

    Node(T val)
    {
        this->value = val;
        this->prev = this->next = NULL;
    }
};

template <class T>
class Stack
{
private:
    Node<T> *head;
    Node<T> *top;
    int length;

public:
    Stack()
    {
        this->head = this->top = NULL;
        this->length = 0;
    }

    /* methods */

    // get length
    int size()
    {
        return this->length;
    }

    // is empty
    bool empty()
    {
        return !this->length;
    }

    // display (only works for int, float, char, string, double)
    void display()
    {
        Node<T> *node = this->head;
        while (node != NULL)
        {
            cout << node->value << " ";
            node = node->next;
        }

        if (this->length)
            cout << endl;
    }

    // display reverse (only works for int, float, char, string, double)
    void displayReverse()
    {
        Node<T> *node = this->top;
        while (node != NULL)
        {
            cout << node->value << " ";
            node = node->prev;
        }

        if (this->length)
            cout << endl;
    }

    // get top
    T getTop()
    {
        return this->top->value;
    }

    // push
    void push(T val)
    {
        Node<T> *newNode = new Node(val);

        if (this->top == NULL)
        {
            this->head = this->top = newNode;
            this->length++;
            return;
        }

        this->top->next = newNode;
        newNode->prev = this->top;
        this->top = newNode;
        this->length++;
    }

    // pop
    T pop()
    {
        Node<T> *delNode = this->top;
        T returnVal = delNode->value;

        if (this->length == 1)
            this->head = this->top = NULL;
        else
        {
            this->top = delNode->prev;
            this->top->next = NULL;
        }

        delete delNode;
        this->length--;

        return returnVal;
    }
};
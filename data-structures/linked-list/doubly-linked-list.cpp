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
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    // display reverse list
    void displayReverse()
    {
        Node *node = this->tail;
        while (node != NULL)
        {
            cout << node->value << " ";
            node = node->prev;
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

    // insertion at specific position
    void insertAtSpecificPosition(int pos, int val)
    {
        if (pos < 1 || pos > (this->lengthCount + 1))
            return;

        if (pos == 1)
        {
            insertAtHead(val);
            return;
        }

        if (pos == (this->lengthCount + 1))
        {
            insertAtTail(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *node = this->head;

        for (int i = 1; i < pos; i++)
        {
            node = node->next;
        }

        newNode->prev = node->prev;
        newNode->prev->next = newNode;
        newNode->next = node;
        node->prev = newNode;
        this->lengthCount++;
    }

    // Search a value (Unique List)
    int getPositionByValue(int val)
    {
        if (this->head == NULL)
            return -1;

        bool isFound = false;
        int pos = 1;
        Node *node = this->head;

        while (node != NULL)
        {
            if (node->value == val)
            {
                isFound = true;
                break;
            }

            node = node->next;
            pos++;
        }

        return isFound ? pos : -1;
    }

    // Search a value (Duplication enabled List)
    int *getPositionsByValue(int val)
    {
        int *foundPositions = new int[this->lengthCount + 1];

        int pos, top;
        pos = 1;
        top = 1;
        Node *node = this->head;

        while (node != NULL)
        {
            if (node->value == val)
            {
                foundPositions[top] = pos;
                top++;
            }

            node = node->next;
            pos++;
        }

        foundPositions = (int *)realloc(foundPositions, sizeof(int) * pos);
        foundPositions[0] = --top;

        return foundPositions;
    }

    // Insertion after a specific value (Unique List)
    void insertAfterSpecificValue(int val, int insertVal)
    {
        int pos = this->getPositionByValue(val);
        if (pos == -1)
            return;
        insertAtSpecificPosition(pos + 1, insertVal);
    }

    // Insertion after a specific value (Duplication enabled List)
    void insertAfterAllSpecificValue(int val, int insertVal)
    {
        int *foundPositions = this->getPositionsByValue(val);
        if (foundPositions[0] == 0)
            return;

        int insertCount = 0;
        for (int i = 1; i <= foundPositions[0]; i++)
        {
            insertAtSpecificPosition(foundPositions[i] + 1 + insertCount, insertVal);
            insertCount++;
        }
    }

    // Deletion at Head
    void deletionAtHead()
    {
        if (this->head == NULL)
            return;

        Node *delNode = this->head;
        if (delNode->next == NULL)
        {
            this->head = NULL;
            this->tail = NULL;
            delete delNode;
            this->lengthCount--;
            return;
        }

        delNode->next->prev = NULL;
        this->head = delNode->next;
        delete delNode;
        this->lengthCount--;
    }

    // Deletion at Tail
    void deletionAtTail()
    {
        if (this->tail == NULL)
            return;

        Node *delNode = this->tail;
        if (delNode->prev == NULL)
        {
            this->head = NULL;
            this->tail = NULL;
            delete delNode;
            this->lengthCount--;
            return;
        }

        delNode->prev->next = NULL;
        this->tail = delNode->prev;
        delete delNode;
        this->lengthCount--;
    }

    // Deletion at a Specific Position
    void deletionAtSpecificPosition(int pos)
    {
        if (pos < 1 || pos > this->lengthCount)
            return;

        if (pos == 1)
        {
            deletionAtHead();
            return;
        }

        if (pos == this->lengthCount)
        {
            deletionAtTail();
            return;
        }

        Node *delNode = this->head;
        for (int i = 1; i < pos; i++)
        {
            delNode = delNode->next;
        }

        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
        delete delNode;
        this->lengthCount--;
    }

    // Deletion by Value (Unique List)
    void deletionByValue(int val)
    {
        int pos = this->getPositionByValue(val);
        if (pos == -1)
            return;
        deletionAtSpecificPosition(pos);
    }

    // Deletion by Value(Duplication enabled List)
    void deletionByValueDuplicate(int val)
    {
        int *foundPositions = this->getPositionsByValue(val);
        if (foundPositions[0] == 0)
            return;

        int deletionCount = 0;
        for (int i = 1; i <= foundPositions[0]; i++)
        {
            deletionAtSpecificPosition(foundPositions[i] - deletionCount);
            deletionCount++;
        }
    }
};

int main()
{
    LinkedList myList;
    myList.insertAtTail(100);
    myList.insertAtHead(15);
    myList.insertAtHead(155);
    myList.insertAtHead(5);
    myList.insertAtTail(500);
    myList.insertAtSpecificPosition(1, 1000);
    myList.insertAtSpecificPosition(7, 1000);
    myList.insertAtSpecificPosition(4, 1000);
    myList.insertAtSpecificPosition(9, 2000);
    myList.insertAtSpecificPosition(9, 5000);
    myList.insertAfterSpecificValue(5000, 75);
    myList.insertAfterAllSpecificValue(1000, 40);
    myList.deletionAtHead();
    myList.deletionAtHead();
    myList.deletionAtTail();
    myList.deletionAtTail();
    myList.deletionAtSpecificPosition(4);
    myList.deletionByValue(100);
    myList.deletionByValueDuplicate(1000);

    cout << "Display List: ";
    myList.display();
    cout << "Display Reverse List: ";
    myList.displayReverse();
    cout << "Length: " << myList.length() << endl;
    if (myList.head != NULL)
    {
        cout << "Head: " << myList.head->value << endl;
        cout << "Tail: " << myList.tail->value << endl;
    }

    cout << "Position of 15: " << myList.getPositionByValue(15) << endl;
    int *foundPositions = myList.getPositionsByValue(1000);
    cout << "Positions of 1000: ";
    if (foundPositions[0] == 0)
    {
        cout << "NULL\n";
    }
    {
        for (int i = 1; i <= foundPositions[0]; i++)
        {
            cout << foundPositions[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
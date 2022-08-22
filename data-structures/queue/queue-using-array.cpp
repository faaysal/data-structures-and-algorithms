#include <bits/stdc++.h>

#define MAX_QUEUE_SIZE 5

using namespace std;

template <class T>
class Queue
{
private:
    int front;
    int rear;
    int length;
    T array[MAX_QUEUE_SIZE];

public:
    Queue()
    {
        front = rear = -1;
        length = 0;
    }

    void enqueue(T val)
    {
        if (front == -1)
        {
            front++;
            rear++;
            array[rear] = val;
            length++;
            return;
        }

        if (((rear + 1) % MAX_QUEUE_SIZE) == front)
        {
            cout << "QUEUE FULL\n";
            return;
        }

        rear = ((rear + 1) % MAX_QUEUE_SIZE);
        array[rear] = val;
        length++;
    }

    T dequeue()
    {
        if (front == -1)
        {
            T garbage;
            cout << "QUEUE EMPTY\n";
            return garbage;
        }

        T returnValue = array[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX_QUEUE_SIZE;

        length--;
        return returnValue;
    }

    T peek()
    {
        if (front == -1)
        {
            T garbage;
            cout << "QUEUE EMPTY\n";
            return garbage;
        }

        return array[front];
    }

    int size()
    {
        return length;
    }

    bool empty()
    {
        return !length;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    q.enqueue(6);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(1);
    q.enqueue(2);

    cout << "Front: " << q.peek() << endl;
    cout << "Length: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    return 0;
}
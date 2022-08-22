#include <bits/stdc++.h>
#include "MYQUEUE.h"

using namespace std;

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.dequeue() << endl;

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Length: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    return 0;
}
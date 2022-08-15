#include <bits/stdc++.h>
using namespace std;
#define MAX_STACK_SIZE 1000

template <class T>
class Stack
{
private:
    T arr[MAX_STACK_SIZE];
    int length;
    int currentTop;

public:
    Stack()
    {
        this->length = 0;
        this->currentTop = -1;
    }

    /* stack methods */

    // get size
    int size()
    {
        return this->length;
    }

    // get top
    T top()
    {
        return this->arr[currentTop];
    }

    // display
    void display()
    {
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";

        if (this->length)
            cout << endl;
    }

    // push
    void push(T val)
    {
        this->currentTop++;
        this->arr[currentTop] = val;
        this->length++;
    }

    // pop
    T pop()
    {
        T val = arr[currentTop];
        this->currentTop--;
        this->length--;
        return val;
    }

    // is empty
    bool empty()
    {
        return !this->length;
    }
};

int main()
{
    /* string stack */
    Stack<string> st;
    st.empty() ? cout << "Empty\n" : cout << "Not Empty\n";
    st.push("a");
    st.push("b");
    st.push("c");
    cout << st.pop() << endl;
    st.push("d");
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    st.empty() ? cout << "Empty\n" : cout << "Not Empty\n";

    st.display();
    if (!st.empty())
        cout << "Top: " << st.top() << endl;
    cout << "Length: " << st.size() << endl;

    /* int stack */
    Stack<int> st2;
    st2.empty() ? cout << "Empty\n" : cout << "Not Empty\n";
    st2.push(10);
    st2.push(20);
    cout << st2.pop() << endl;
    st2.push(30);
    st2.push(40);
    st2.push(50);
    cout << st2.pop() << endl;
    cout << st2.pop() << endl;
    st2.empty() ? cout << "Empty\n" : cout << "Not Empty\n";

    st2.display();
    if (!st2.empty())
        cout << "Top: " << st2.top() << endl;
    cout << "Length: " << st2.size() << endl;

    return 0;
}
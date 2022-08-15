#include <bits/stdc++.h>
#include "MYSTACK.h" // contains all code about stack
using namespace std;

int main()
{
    /* int stack */
    Stack<int> st;
    st.push(5);
    st.push(15);
    st.push(115);
    st.push(1115);
    st.push(11115);

    if (!st.empty())
        cout << "OUT: " << st.pop() << endl;

    if (!st.empty())
        cout << "OUT: " << st.pop() << endl;

    st.display();
    st.displayReverse();
    if (!st.empty())
        cout << "Top: " << st.getTop() << endl;
    cout << "Length: " << st.size() << endl;

    /* string stack */
    Stack<string> st2;
    st2.push("Fahim");
    st2.push("Farjana");
    st2.push("Farhan");
    st2.push("Fariz");
    st2.push("Rafi");

    if (!st2.empty())
        cout << "OUT: " << st2.pop() << endl;

    st2.display();
    st2.displayReverse();
    if (!st2.empty())
        cout << "Top: " << st2.getTop() << endl;
    cout << "Length: " << st2.size() << endl;

    return 0;
}
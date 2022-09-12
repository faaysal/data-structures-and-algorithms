#include <bits/stdc++.h>

using namespace std;

class PirorityOueue
{
private:
    vector<int> v;

    void heapify(vector<int> &v, int currentIndex)
    {
        int largestIndex = currentIndex;
        int leftChildIndex = (currentIndex * 2 + 1);
        int rightChildIndex = (currentIndex * 2 + 2);

        if (leftChildIndex < v.size() && v[leftChildIndex] > v[largestIndex])
            largestIndex = leftChildIndex;

        if (rightChildIndex < v.size() && v[rightChildIndex] > v[largestIndex])
            largestIndex = rightChildIndex;

        if (currentIndex != largestIndex)
        {
            swap(v[currentIndex], v[largestIndex]);
            heapify(v, largestIndex);
        }
    }

public:
    int top()
    {
        return v.at(0);
    }

    void push(int val)
    {
        v.push_back(val);

        int lastNonLeadIndex = (v.size() / 2) - 1;

        for (int i = lastNonLeadIndex; i >= 0; i--)
        {
            heapify(v, i);
        }
    }

    void pop()
    {
        v[0] = v[v.size() - 1];
        v.pop_back();

        int lastNonLeadIndex = (v.size() / 2) - 1;

        for (int i = lastNonLeadIndex; i >= 0; i--)
        {
            heapify(v, i);
        }
    }

    bool empty()
    {
        return !v.size();
    }
};

int main()
{
    int n, val;
    cin >> n;
    PirorityOueue *pq = new PirorityOueue();

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        pq->push(val);
    }

    while (!pq->empty())
    {
        cout << pq->top() << endl;
        pq->pop();
    }

    return 0;
}
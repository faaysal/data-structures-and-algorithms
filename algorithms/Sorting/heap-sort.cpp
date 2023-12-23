#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int> &v, int n, int currentIndex)
{
    int largestIndex = currentIndex;
    int leftChildIndex = (currentIndex * 2 + 1);
    int rightChildIndex = (currentIndex * 2 + 2);

    if (leftChildIndex < n && v[leftChildIndex] > v[largestIndex])
        largestIndex = leftChildIndex;

    if (rightChildIndex < n && v[rightChildIndex] > v[largestIndex])
        largestIndex = rightChildIndex;

    if (currentIndex != largestIndex)
    {
        swap(v[currentIndex], v[largestIndex]);
        heapify(v, n, largestIndex);
    }
}

void heapSort(vector<int> &v)
{
    int lastNonLeafIndex = (v.size() / 2) - 1;
    for (int i = lastNonLeafIndex; i >= 0; i--)
    {
        heapify(v, v.size(), i);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main()
{
    int n, val;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.push_back(val);
    }

    heapSort(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
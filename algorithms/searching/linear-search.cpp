#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int val)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }

    i = -1;
    return i;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val;
    cout << "Please enter the value you want to search: ";
    cin >> val;

    int index = linear_search(arr, n, val);
    cout << index;

    return 0;
}
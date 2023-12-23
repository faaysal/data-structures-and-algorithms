#include <iostream>
using namespace std;

// recursive way
/* int binary_search(int arr[], int left, int right, int val)
{
    if (left > right)
    {
        return -1;
    }
    else
    {
        int mid = (left + right) / 2;
        // cout << "MID: " << mid << endl;
        if (val == arr[mid])
            return mid;
        else if (val < arr[mid])
            return binary_search(arr, left, mid - 1, val);
        else
            return binary_search(arr, mid + 1, right, val);
    }
} */

// using while loop (more efficient way - less memory)
int binary_search(int arr[], int left, int right, int val)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // cout << "MID: " << mid << endl;
        if (val == arr[mid])
            return mid;
        else if (val < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
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

    int index = binary_search(arr, 0, n - 1, val);
    cout << index << endl;

    return 0;
}
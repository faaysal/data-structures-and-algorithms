#include <iostream>
using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// insertion sort implementation
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << "It: " << i << endl;
        print_arr(arr, n);
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            print_arr(arr, n);
            j--;
        }
        arr[j + 1] = key;
        print_arr(arr, n);
        cout << endl;
    }
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

    insertion_sort(arr, n);

    cout << "ARRAY: ";
    print_arr(arr, n);

    return 0;
}

/*

1st Iteration:  5 1 3 8 2 2 -> 1 5 3 8 2 2
2nd Iteration:  1 5 3 8 2 2 -> 1 3 5 8 2 2
3rd Iteration: 1 3 5 8 2 2 -> 1 3 5 8 2 2
4th Iteration:  1 3 5 8 2 2 -> 1 2 3 5 8 2
5thy Iteration: 1 2 3 5 8 2 -> 1 2 2 3 5 8

 */
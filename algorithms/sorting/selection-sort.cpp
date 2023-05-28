#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i; j < n; j++)
        {
            min_index = arr[j] < arr[min_index] ? j : min_index;
        }

        if (min_index != i)
        {
            int tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}

int main()
{
    int n = 5;
    int arr[5] = { 10, 20, 5, 25, 13 };
    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
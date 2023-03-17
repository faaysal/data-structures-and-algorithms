
#include <bits/stdc++.h>
using namespace std;

// void sort(int arr[], int n){
//     int k=n-1,swap_count=0;
//     do{
//         swap_count=0;
//         for(int j=0;j<k;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(&arr[j],&arr[j+1]);
//                 swap_count++;
//             }
//         }
//         k--;
//         printf("%d times loop\n",++count);
//         printArr(arr,n);
//     } while(swap_count);
// }

void sort(int arr[], int n)
{
    int k = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        k--;
    }
}

int main()
{
    int n = 5;
    int arr[5] = {3, 2, 1, 4, 5};
    sort(arr, n);

    return 0;
}

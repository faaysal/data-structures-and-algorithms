#include <iostream>
using namespace std;

void merge(int a[], int b, int e, int mid) {
  int x = e - b + 1;
  int arr[x];
  int idx = 0, st1 = b, st2 = mid + 1;
  while(st1 <= mid && st2 <= e) {
    if(a[st1] <= a[st2]) {
      arr[idx++] = a[st1++];
    }
    else {
      arr[idx++] = a[st2++];
    }
  }
  while(st1 <= mid) {
    arr[idx++] = a[st1++];
  }
  while(st2 <= e) {
    arr[idx++] = a[st2++];
  }

  for(int i = b, k = 0; i <= e; i++, k++) {
    a[i] = arr[k];
  }
}

void merge_sort(int a[], int b, int e) {
  if(b == e) return;
  int mid = (b + e) / 2;
  merge_sort(a, b, mid);
  merge_sort(a, mid + 1, e);
  merge(a, b, e, mid);
}

int main() {
  int n = 10;
  int a[n] = {4, 2, 3, 1, 5, 8, 7, 11, 9, 6};
  merge_sort(a, 0, n - 1);
  for(int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
    return 0;
}
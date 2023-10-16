#include <iostream>
using namespace std;

int partition(int a[], int b, int e) {
  int l = b, r = e;
  int pivot_item = a[b];
  while (l < r) {
    while (l < e and a[l] <= pivot_item) l++;
    while (r > b and a[r] >= pivot_item) r--;
    if (l < r) {
      swap(a[l], a[r]);
    }
  }
  a[b] = a[r];
  a[r] = pivot_item;
  return r;
}


void quick_sort(int a[], int b, int e) {
  if (b >= e) return;
  int p = partition(a, b, e);
  quick_sort(a, b, p - 1);
  quick_sort(a, p + 1, e);
}

int main() {

  int n = 5;
  int a[n] = { 5, 4, 2, 1, 3 };

  quick_sort(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}
#include <iostream>
using namespace std;

class Node { // linked list to store taken objects
public:
  int value;
  Node* next;
  Node(int val) {
    value = val;
    next = NULL;
  }
};

void display(Node*& head) {
  Node* node = head;
  while (node != NULL) {
    cout << node->value << ' ';
    node = node->next;
  }
  cout << '\n';
}

void insert_at_tail(Node*& head, int val) {
  Node* newNode = new Node(val);
  if (head == NULL) {
    head = newNode;
    return;
  }
  Node* node = head;
  while (node->next != NULL) {
    node = node->next;
  }
  node->next = newNode;
}

Node* head;
struct Item {
  int profit;
  int weight;int index;
};

float get_ratio(Item i) { // return profit/weigth ratio of an Item
  return (float(i.profit) / float(i.weight));
}
void selection_sort(Item arr[], int n) { // sort based on ratio
  for (int i = 0; i < n - 1; i++) {
    int max_index = i;
    for (int j = i; j < n; j++) {
      max_index = get_ratio(arr[j]) >= get_ratio(arr[max_index]) ? j :
        max_index;
    }
    if (max_index != i) {
      swap(arr[i], arr[max_index]);
    }
  }
}

float fractional_knapsack(int W, Item arr[], int n) {
  selection_sort(arr, n);
  float ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].weight <= W) {
      W -= arr[i].weight;
      ans += arr[i].profit;
      insert_at_tail(head, arr[i].index + 1);
    }
    else {
      ans += arr[i].profit * (float(W) / float(arr[i].weight));
      insert_at_tail(head, arr[i].index + 1);
      break;
    }
  }
  return ans;
}

int main() {
  cout << "Enter the number of Item: ";
  int n; cin >> n;
  cout << "Enter Knapsack Size: ";int W; cin >> W;
  Item arr[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter Item " << i + 1 << "s weight: ";
    cin >> arr[i].weight;
    cout << "Enter Item " << i + 1 << "s profit: ";
    cin >> arr[i].profit;
    arr[i].index = i;
  }
  head = NULL;
  float ans = fractional_knapsack(W, arr, n);
  cout << "Maximum profit: " << ans << '\n';
  cout << "Object's which are taken: ";
  display(head);
  return 0;
}
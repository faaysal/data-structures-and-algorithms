#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}

vector<int> merge_sort(vector<int> v) {
    if (v.size() <= 1) return v;
    int mid = v.size() / 2;
    vector<int> v1, v2;
    for (int i = 0; i < mid; i++) {
        v1.push_back(v[i]);
    }
    for (int i = mid; i < v.size(); i++) {
        v2.push_back(v[i]);
    }

    v1 = merge_sort(v1);
    v2 = merge_sort(v2);

    // merge v1 and v2
    vector<int> ans;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            ans.push_back(v1[i]);
            i++;
        }
        else {
            ans.push_back(v2[j]);
            j++;
        }
    }
    for (; i < v1.size(); i++) {
        ans.push_back(v1[i]);
    }
    for (; j < v2.size(); j++) {
        ans.push_back(v2[j]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int val;
    vector<int> v;
    while (cin >> val) {
        v.push_back(val);
    }
    v = merge_sort(v);
    print(v);

    return 0;
}
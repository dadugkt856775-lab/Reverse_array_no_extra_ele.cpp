#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<int>& a, int left, int mid, int right) {
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i++]);
        } else {
            temp.push_back(a[j++]);
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp.push_back(a[i++]);

    while (j <= right)
        temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];

    return count;
}

long long mergeSort(vector<int>& a, int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += mergeSort(a, left, mid);
    count += mergeSort(a, mid + 1, right);
    count += mergeAndCount(a, left, mid, right);

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    cout << "Inversion Count = "
         << mergeSort(a, 0, n - 1);

    return 0;
}

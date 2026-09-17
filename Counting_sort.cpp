#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    int minimum = *min_element(a.begin(), a.end());
    int maximum = *max_element(a.begin(), a.end());

    vector<int> count(maximum - minimum + 1, 0);

    for (int x : a)
        count[x - minimum]++;

    cout << "Sorted Array: ";

    for (int i = 0; i < count.size(); i++) {
        while (count[i]--) {
            cout << i + minimum << " ";
        }
    }

    return 0;
}

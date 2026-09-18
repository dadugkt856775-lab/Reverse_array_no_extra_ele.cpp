#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    int farthest = 0;

    for (int i = 0; i < n; i++) {
        if (i > farthest) {
            cout << "Cannot Reach Last Index" << endl;
            return 0;
        }

        farthest = max(farthest, i + a[i]);
    }

    cout << "Last Index is Reachable" << endl;

    return 0;
}

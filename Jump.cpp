#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    if (n <= 1) {
        cout << "Minimum Jumps: 0" << endl;
        return 0;
    }

    if (a[0] == 0) {
        cout << "Cannot Reach End" << endl;
        return 0;
    }

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + a[i]);

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) {
                cout << "Minimum Jumps: " << jumps << endl;
                return 0;
            }
        }

        if (i >= farthest) {
            cout << "Cannot Reach End" << endl;
            return 0;
        }
    }

    cout << "Minimum Jumps: " << jumps << endl;

    return 0;
}

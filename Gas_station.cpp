#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> gas(n), cost(n);

    for (int &x : gas) cin >> x;
    for (int &x : cost) cin >> x;

    int total = 0;
    int current = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        total += gas[i] - cost[i];
        current += gas[i] - cost[i];

        if (current < 0) {
            start = i + 1;
            current = 0;
        }
    }

    if (total >= 0)
        cout << "Starting Station: " << start << endl;
    else
        cout << "Circuit Not Possible" << endl;

    return 0;
}

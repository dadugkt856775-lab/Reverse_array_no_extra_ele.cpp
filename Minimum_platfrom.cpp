#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arrival(n), departure(n);

    for (int &x : arrival) cin >> x;
    for (int &x : departure) cin >> x;

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0, j = 0;
    int platforms = 0, answer = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            answer = max(answer, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    cout << "Minimum Platforms Required: " << answer << endl;

    return 0;
}

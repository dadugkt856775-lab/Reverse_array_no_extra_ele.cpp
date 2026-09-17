#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> activities(n);

    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;
        activities[i] = {finish, start};
    }

    sort(activities.begin(), activities.end());

    int count = 0;
    int lastFinish = -1;

    cout << "Selected Activities:\n";

    for (auto [finish, start] : activities) {
        if (start >= lastFinish) {
            cout << start << " -> " << finish << "\n";

            lastFinish = finish;
            count++;
        }
    }

    cout << "Maximum Activities = " << count;

    return 0;
}

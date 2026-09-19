#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int index, int target,
           vector<int> &current) {

    if (target == 0) {
        for (int x : current)
            cout << x << " ";
        cout << endl;
        return;
    }

    if (target < 0 || index == a.size())
        return;

    current.push_back(a[index]);

    solve(a, index, target - a[index], current);

    current.pop_back();

    solve(a, index + 1, target, current);
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> current;

    cout << "Combinations:\n";
    solve(a, 0, target, current);

    return 0;
}

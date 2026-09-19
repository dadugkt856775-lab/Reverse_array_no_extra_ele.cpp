#include <bits/stdc++.h>
using namespace std;

void generate(vector<int> &a, int start, int k, vector<int> &current) {
    if (current.size() == k) {
        for (int x : current)
            cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < a.size(); i++) {
        current.push_back(a[i]);

        generate(a, i + 1, k, current);

        current.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> current;

    cout << "Combinations:\n";
    generate(a, 0, k, current);

    return 0;
}

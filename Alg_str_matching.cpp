#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    string combined = pattern + "$" + text;

    vector<int> z = zFunction(combined);

    cout << "Pattern found at indices: ";

    bool found = false;

    for (int i = 0; i < z.size(); i++) {
        if (z[i] == pattern.size()) {
            cout << i - pattern.size() - 1 << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.size();
    int m = pattern.size();

    if (m > n) {
        cout << "Pattern Not Found";
        return 0;
    }

    const long long base = 256;
    const long long mod = 1000000007;

    long long patternHash = 0;
    long long textHash = 0;
    long long power = 1;

    for (int i = 0; i < m - 1; i++)
        power = (power * base) % mod;

    for (int i = 0; i < m; i++) {
        patternHash =
            (patternHash * base + pattern[i]) % mod;

        textHash =
            (textHash * base + text[i]) % mod;
    }

    bool found = false;

    for (int i = 0; i <= n - m; i++) {

        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern) {
                cout << "Pattern found at index "
                     << i << "\n";
                found = true;
            }
        }

        if (i < n - m) {
            textHash =
                (textHash -
                 text[i] * power % mod + mod) % mod;

            textHash =
                (textHash * base + text[i + m]) % mod;
        }
    }

    if (!found)
        cout << "Pattern Not Found";

    return 0;
}

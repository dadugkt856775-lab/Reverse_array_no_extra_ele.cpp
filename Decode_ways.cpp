#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    if (s[0] == '0') {
        cout << "Number of Ways: 0" << endl;
        return 0;
    }

    vector<long long> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];

        int number = stoi(s.substr(i - 2, 2));

        if (number >= 10 && number <= 26)
            dp[i] += dp[i - 2];
    }

    cout << "Number of Ways: " << dp[n] << endl;

    return 0;
}

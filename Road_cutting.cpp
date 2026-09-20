#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> price(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> price[i];

    vector<int> dp(n + 1, 0);

    for (int length = 1; length <= n; length++) {
        for (int cut = 1; cut <= length; cut++) {
            dp[length] = max(
                dp[length],
                price[cut] + dp[length - cut]
            );
        }
    }

    cout << "Maximum Profit: " << dp[n] << endl;

    return 0;
}

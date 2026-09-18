#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);

    for (int &x : coins)
        cin >> x;

    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    cout << "Number of Ways: " << dp[amount] << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int x : a) {
        for (int sum = target; sum >= x; sum--) {
            dp[sum] = dp[sum] || dp[sum - x];
        }
    }

    if (dp[target])
        cout << "Subset Exists";
    else
        cout << "Subset Does Not Exist";

    return 0;
}

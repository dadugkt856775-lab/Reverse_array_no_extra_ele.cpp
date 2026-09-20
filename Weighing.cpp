#include <bits/stdc++.h>
using namespace std;

struct Job {
    int start, finish, profit;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (auto& job : jobs)
        cin >> job.start >> job.finish >> job.profit;

    sort(jobs.begin(), jobs.end(),
         [](Job a, Job b) {
             return a.finish < b.finish;
         });

    vector<int> dp(n);

    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int include = jobs[i].profit;

        int previous = -1;

        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].finish <= jobs[i].start) {
                previous = j;
                break;
            }
        }

        if (previous != -1)
            include += dp[previous];

        dp[i] = max(dp[i - 1], include);
    }

    cout << "Maximum Profit: " << dp[n - 1] << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (auto &job : jobs) {
        cin >> job.id >> job.deadline >> job.profit;
    }

    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<char> slot(maxDeadline + 1, '-');

    int totalProfit = 0;

    for (auto job : jobs) {
        for (int t = job.deadline; t >= 1; t--) {
            if (slot[t] == '-') {
                slot[t] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Job Sequence: ";

    for (int i = 1; i <= maxDeadline; i++)
        if (slot[i] != '-')
            cout << slot[i] << " ";

    cout << "\nMaximum Profit: " << totalProfit << endl;

    return 0;
}

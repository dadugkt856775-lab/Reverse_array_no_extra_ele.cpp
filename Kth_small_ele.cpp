#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (auto& row : matrix)
        for (int& x : row)
            cin >> x;

    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    for (int i = 0; i < n; i++)
        pq.push({matrix[i][0], i, 0});

    int answer = -1;

    for (int count = 0; count < k; count++) {
        auto [value, row, col] = pq.top();
        pq.pop();

        answer = value;

        if (col + 1 < n)
            pq.push({matrix[row][col + 1],
                     row, col + 1});
    }

    cout << "K-th Smallest Element = " << answer;

    return 0;
}

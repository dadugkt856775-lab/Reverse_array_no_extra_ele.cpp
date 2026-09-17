#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(
        rows, vector<int>(cols)
    );

    for (auto& row : grid)
        for (int& x : row)
            cin >> x;

    vector<vector<int>> dp(
        rows, vector<int>(cols, 0)
    );

    dp[0][0] = grid[0][0];

    for (int j = 1; j < cols; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < rows; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] =
                grid[i][j] +
                min(dp[i - 1][j],
                    dp[i][j - 1]);
        }
    }

    cout << "Minimum Path Sum = "
         << dp[rows - 1][cols - 1];

    return 0;
}

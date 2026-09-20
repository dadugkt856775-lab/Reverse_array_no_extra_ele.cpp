#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph,
            vector<int>& path, int pos) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool solve(vector<vector<int>>& graph,
           vector<int>& path, int pos) {
    int n = graph.size();

    if (pos == n)
        return graph[path[n - 1]][path[0]];

    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (solve(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (auto& row : graph)
        for (int& x : row)
            cin >> x;

    vector<int> path(n, -1);
    path[0] = 0;

    if (solve(graph, path, 1)) {
        cout << "Hamiltonian Cycle: ";

        for (int x : path)
            cout << x << " ";

        cout << path[0] << endl;
    } else {
        cout << "No Hamiltonian Cycle" << endl;
    }

    return 0;
}

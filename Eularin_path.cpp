#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& graph,
         vector<bool>& visited) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v])
            dfs(v, graph, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    int start = -1;

    for (int i = 0; i < n; i++) {
        if (degree[i] > 0) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        cout << "Eulerian Circuit" << endl;
        return 0;
    }

    vector<bool> visited(n, false);
    dfs(start, graph, visited);

    for (int i = 0; i < n; i++) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "No Eulerian Path or Circuit" << endl;
            return 0;
        }
    }

    int odd = 0;

    for (int d : degree) {
        if (d % 2 != 0)
            odd++;
    }

    if (odd == 0)
        cout << "Eulerian Circuit" << endl;
    else if (odd == 2)
        cout << "Eulerian Path" << endl;
    else
        cout << "No Eulerian Path or Circuit" << endl;

    return 0;
}

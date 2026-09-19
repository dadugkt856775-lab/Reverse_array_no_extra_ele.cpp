#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int u, int parent,
         vector<vector<int>> &graph,
         vector<int> &tin,
         vector<int> &low,
         vector<bool> &visited) {

    visited[u] = true;
    tin[u] = low[u] = timer++;

    for (int v : graph[u]) {
        if (v == parent)
            continue;

        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u, graph, tin, low, visited);

            low[u] = min(low[u], low[v]);

            if (low[v] > tin[u]) {
                cout << "Bridge: " << u << " - " << v << endl;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> tin(n, -1), low(n, -1);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, -1, graph, tin, low, visited);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(int u, int parent,
         vector<vector<int>> &graph,
         vector<int> &tin,
         vector<int> &low,
         vector<bool> &visited,
         vector<bool> &articulation) {

    visited[u] = true;
    tin[u] = low[u] = timer++;

    int children = 0;

    for (int v : graph[u]) {
        if (v == parent)
            continue;

        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        }
        else {
            dfs(v, u, graph, tin, low, visited, articulation);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= tin[u])
                articulation[u] = true;

            children++;
        }
    }

    if (parent == -1 && children > 1)
        articulation[u] = true;
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
    vector<bool> articulation(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, -1, graph, tin, low, visited, articulation);
    }

    cout << "Articulation Points: ";

    for (int i = 0; i < n; i++) {
        if (articulation[i])
            cout << i << " ";
    }

    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    int total = 0;
    int edgesUsed = 0;

    for (int start = 0; start < n; start++) {
        if (visited[start])
            continue;

        pq.push({0, start});

        while (!pq.empty()) {
            auto [weight, u] = pq.top();
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            total += weight;

            if (weight != 0)
                edgesUsed++;

            for (auto [v, w] : graph[u]) {
                if (!visited[v])
                    pq.push({w, v});
            }
        }
    }

    if (edgesUsed != n - 1)
        cout << "Graph is disconnected";
    else
        cout << "MST Cost = " << total;

    return 0;
}

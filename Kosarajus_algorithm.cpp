#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>>& graph,
          vector<bool>& visited, stack<int>& st) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v])
            dfs1(v, graph, visited, st);
    }

    st.push(u);
}

void dfs2(int u, vector<vector<int>>& reversed,
          vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);

    for (int v : reversed[u]) {
        if (!visited[v])
            dfs2(v, reversed, visited, component);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n), reversed(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        reversed[v].push_back(u);
    }

    stack<int> st;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(i, graph, visited, st);
    }

    fill(visited.begin(), visited.end(), false);

    int count = 0;

    cout << "Strongly Connected Components:\n";

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            vector<int> component;
            dfs2(u, reversed, visited, component);

            cout << "Component " << ++count << ": ";

            for (int x : component)
                cout << x << " ";

            cout << endl;
        }
    }

    return 0;
}

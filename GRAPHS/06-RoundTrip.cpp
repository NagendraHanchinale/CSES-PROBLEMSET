#include <bits/stdc++.h>
using namespace std;

const string noSolution = "IMPOSSIBLE";
vector<int> parent, vis;
int startNode, endNode;
bool found = false;

void dfs(int node, vector<vector<int>> &adj) {
    vis[node] = 1;
    for (auto nei : adj[node]) {
        if (nei == parent[node]) continue; 
        if (!vis[nei]) {
            parent[nei] = node;
            dfs(nei, adj);
            if (found) return;
        } else {
            startNode = nei;
            endNode = node;
            found = true;
            return;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj);
            if (found) break;
        }
    }

    if (!found) {
        cout << noSolution;
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(startNode);
    for (int v = endNode; v != startNode; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(startNode);

    cout << cycle.size() << endl;
    for (auto x : cycle) cout << x << " ";
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const string noSolution = "IMPOSSIBLE";

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &col, int colour) {
    vis[node] = 1;
    col[node] = colour;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (!dfs(it, adj, vis, col, 3 - colour))
                return false;
        }
        else if (col[it] == col[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1, 0), col(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (!dfs(i, adj, vis, col, 1)) {
                cout << noSolution << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << col[i] << " ";
    cout << endl;
}

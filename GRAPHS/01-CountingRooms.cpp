#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int rooms = 0;

void dfs(vector<vector<char>> &building, int i, int j, vector<vector<int>> &vis) {
    if (vis[i][j] == 1) return;
    vis[i][j] = 1;

    for (auto it : dir) {
        int dx = it.first;
        int dy = it.second;
        int x = i + dx;
        int y = j + dy;
        if (x >= 0 && y >= 0 &&
            x < (int)building.size() && y < (int)building[0].size() && !vis[x][y] && building[x][y] == '.') {
            dfs(building, x, y, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> building(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            cin >> building[i][j];
        }
    }

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0 ; j < m ; ++j) {
            if (!vis[i][j] && building[i][j] == '.') {
                dfs(building, i, j, vis);
                rooms++;
            }
        }
    }

    cout << rooms << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'A') start = make_pair(i, j);
            if (map[i][j] == 'B') end = make_pair(i, j);
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
    vector<vector<char>> move(n, vector<char>(m));
    queue<pair<int, int>> q;

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string dirChar = "DURL";

    q.push(start);
    vis[start.first][start.second] = 1;

    bool found = false;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (make_pair(x, y) == end) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int i = x + dir[d].first;
            int j = y + dir[d].second;

            if (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j] && map[i][j] != '#') {
                vis[i][j] = 1;
                q.push(make_pair(i, j));
                parent[i][j] = make_pair(x, y);
                move[i][j] = dirChar[d];
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        string path;
        int x = end.first, y = end.second;
        while (make_pair(x, y) != start) {
            char step = move[x][y];
            path += step;
            int px = parent[x][y].first;
            int py = parent[x][y].second;
            x = px;
            y = py;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << path.size() << "\n" << path << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const string step = "DURL";

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> labyR(n, vector<char>(m));
    vector<vector<int>> monsterTime(n, vector<int>(m, INT_MAX));
    vector<vector<int>> playerTime(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> stepDir(n, vector<char>(m, 0)); 

    int sr = -1, sc = -1;
    queue<pair<int,int>> mq;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> labyR[i][j];
            if (labyR[i][j] == 'A') {
                sr = i;
                sc = j;
            }
            if (labyR[i][j] == 'M') {
                monsterTime[i][j] = 0;
                mq.push(make_pair(i, j));
            }
        }
    }

    while (!mq.empty()) {
        int x = mq.front().first;
        int y = mq.front().second;
        mq.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k].first;
            int ny = y + dir[k].second;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && labyR[nx][ny] != '#') {
                if (monsterTime[nx][ny] > monsterTime[x][y] + 1) {
                    monsterTime[nx][ny] = monsterTime[x][y] + 1;
                    mq.push(make_pair(nx, ny));
                }
            }
        }
    }

    queue<pair<int,int>> pq;
    pq.push(make_pair(sr, sc));
    playerTime[sr][sc] = 0;

    while (!pq.empty()) {
        int i = pq.front().first;
        int j = pq.front().second;
        pq.pop();

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            string path;
            int ci = i, cj = j;
            while (!(ci == sr && cj == sc)) {
                path.push_back(stepDir[ci][cj]);
                int pi = parent[ci][cj].first;
                int pj = parent[ci][cj].second;
                ci = pi;
                cj = pj;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n" << path << endl;
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k].first;
            int nj = j + dir[k].second;
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && labyR[ni][nj] != '#') {
                if (playerTime[ni][nj] > playerTime[i][j] + 1 &&
                    playerTime[i][j] + 1 < monsterTime[ni][nj]) {
                    
                    playerTime[ni][nj] = playerTime[i][j] + 1;
                    parent[ni][nj] = make_pair(i, j);
                    stepDir[ni][nj] = step[k];
                    pq.push(make_pair(ni, nj));
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}

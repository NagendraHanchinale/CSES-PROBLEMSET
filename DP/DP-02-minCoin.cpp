#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int helper(vector<int> &a, vector<vector<int>> &dp, int i, int target) {
    if (target == 0) return 0;
    if (target < 0 || i >= (int)a.size()) return INF;
    if (dp[i][target] != -1) return dp[i][target];

    int take = INF;
    if (a[i] <= target) take = 1 + helper(a, dp, i, target - a[i]);
    int skip = helper(a, dp, i + 1, target);

    return dp[i][target] = min(take, skip);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = helper(a, dp, 0, x);
    cout << (ans == INF ? -1 : ans) << endl;
}

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= x; ++j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % M;
        }
    }

    cout << dp[x] << '\n';
    return 0;
}

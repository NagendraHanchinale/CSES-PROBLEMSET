#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n , x;
    cin >> n >> x;
    vector<int> h(n) , s(n);
    for(int i = 0 ;i < n; ++i)cin >> h[i];
    for(int i = 0 ;i < n; ++i)cin >> s[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1 , 0));
    for(int i = 0 ; i <= n ; ++i)dp[i][0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j <= x; ++j){
            if(h[i - 1] <= j){
                dp[i][j] = dp[i - 1][j - h[i - 1]] + s[i - 1];
            }
            dp[i][j] = max(dp[i][j],dp[i - 1][j]);
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
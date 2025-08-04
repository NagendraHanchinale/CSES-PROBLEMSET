#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> coins;
vector<int> dp;

int helper(int x){
    if(x == 0)return 1;
    if(x < 0)return 0;
    if(dp[x] != -1)return dp[x];
     int ways =0 ;
     for(auto c : coins){
         if(x - c >= 0){
            ways = (ways + helper(x - c)) % MOD;
         }
     }
     return dp[x] = ways;
}

int main() {
    int n, x;
    cin >> n >> x;
    coins.resize(n);
    dp.assign(x + 1 , -1);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    
    cout << helper(x) << endl;
    return 0;
}

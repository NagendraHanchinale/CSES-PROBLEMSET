#include<bits/stdc++.h>
using namespace std;
vector<int> dp;

int helper(int n){
    if(n == 0)return 0;
    if(dp[n] != INT_MAX)return dp[n];
    string num = to_string(n);
    for(auto c : num){
        int dig = c - '0';
        if(dig != 0 )dp[n] = min(dp[n] , helper(n - dig) + 1);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    dp.assign(n + 1 , INT_MAX);
    cout << helper(n) << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int n;
int helper(vector<string> &g , int i , int j , vector<vector<int>> &dp){
    if(i >= n || j >= n || g[i][j] == '*')return 0;
    if(i == n - 1 && j == n - 1)return 1;
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = (helper(g,i + 1 , j,dp) % M+ helper(g,i , j + 1,dp) % M) % M;
}

int main() {
    cin >> n;
    vector<string> grid(n);
    vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1));
    for(int i = 0 ;i < n; ++i)cin>> grid[i];
    cout << helper(grid,0,0,dp) << endl;
    return 0;
}
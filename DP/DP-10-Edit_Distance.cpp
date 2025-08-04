#include<bits/stdc++.h>
using namespace std;

int n , m;

int helper(string &a , string &b , int i , int j , vector<vector<int>> &dp){
    if(i == n) return m - j;
    if(j == m) return n - i;

    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j])
        return dp[i][j] = helper(a, b, i + 1, j + 1, dp);

    int insOp = helper(a, b, i, j + 1, dp) + 1;
    int delOp = helper(a, b, i + 1, j, dp) + 1;
    int repOp = helper(a, b, i + 1, j + 1, dp) + 1;

    return dp[i][j] = min({insOp, delOp, repOp});
}


int main() {
    string s1 , s2;
    cin >> s1 >> s2;
    n = s1.size() ; m = s2.size();
    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , -1));
    int ans = helper(s1 , s2 , 0 , 0 , dp);
    cout << ans << endl;
    return 0;
}
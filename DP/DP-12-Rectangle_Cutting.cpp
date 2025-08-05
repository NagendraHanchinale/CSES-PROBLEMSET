#include<bits/stdc++.h>
using namespace std;


/*
Intuition:

- We cannot use a greedy approach here, because choosing the largest possible square first
  may not lead to the minimum number of cuts overall.

- So, we try all possible combinations of cuts using **recursion with memoization (DP)**.

- For any rectangle of size (a × b):

    - If a == b → It's already a square, so no cuts needed → return 0.

    - Otherwise, we try:
        1. All possible vertical cuts:
            - Cut at column v (from 1 to b - 1)
            - This splits the rectangle into two smaller rectangles:
                - a × v
                - a × (b - v)
            - Total cuts = 1 (for this cut) + cuts required for both resulting rectangles

        2. All possible horizontal cuts:
            - Cut at row h (from 1 to a - 1)
            - This splits the rectangle into:
                - h × b
                - (a - h) × b
            - Total cuts = 1 + cuts for both resulting rectangles

- We take the minimum over all valid vertical and horizontal cuts.*/

/* //top down approach , but would face TLE due to deep recursion stack. :-(
int helper( int i  , int j , vector<vector<int>> &dp){
    if(i == j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = INT_MAX;
    for(int h = 1 ; h <= i - 1 ; ++h){
        ans = min(ans, helper(h , j , dp) + helper( i - h , j, dp) + 1);
    }
    for(int v = 1 ; v <= j - 1 ; ++v){
        ans = min(ans, helper( i , v , dp) + helper( i , j - v , dp) + 1);
    }
    return dp[i][j] = ans;
}
*/

int main() {
    int a , b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    for(int i = 1 ; i <= a ; ++i){
        for(int j = 1 ; j <= b ; ++j){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int v = 1 ; v <= i - 1 ; ++v){
                dp[i][j] = min(dp[i][j] , dp[v][j] + dp[i - v][j] + 1);
            }
            for(int h = 1 ; h <= j - 1 ; ++h){
                dp[i][j] = min(dp[i][j] , dp[i][j - h] + dp[i][h] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}

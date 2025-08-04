#include<bits/stdc++.h>
using namespace std;
 
 
int main() {
    int n , m;
    cin >> n >> m;
    vector<int> a(n) ,b(m);
    for(int i = 0 ; i < n ; ++i)cin >> a[i];
    for(int i = 0 ; i < m ; ++i)cin >> b[i];
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1 , 0));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    
    int  i = n , j = m;
    vector<int> lcs;
    while(i >= 1 && j >= 1){
        if(a[i - 1] == b[j - 1]){
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }else if(dp[i][j - 1] < dp[i - 1][j]){
            i--;
        }else j--;
    }
    cout << dp[n][m] << endl;
    for(int i = (int)lcs.size() - 1; i >= 0 ; --i)cout << lcs[i] << " ";
    cout << endl;
 
    return 0;
}
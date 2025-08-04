#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
vector<int> arr;
vector<vector<int>> dp;

int solve(int i, int prev) {
   if(i == n)return 1;
   if(dp[i][prev] != -1)return dp[i][prev];
   int res = 0;
   if(arr[i] != 0){
      if(abs(arr[i] - prev) <= 1){
         res = solve(i + 1 , arr[i]);
      }
   }else{
      for(int d = prev - 1 ; d <= prev + 1 ; ++d){
         if(d >= 1 && d <= m){
            res = (res + solve(i + 1 , d)) % MOD;
         }
      }
   }
   return dp[i][prev] = res;
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (auto &x : arr) cin >> x;

    dp.assign(n + 1, vector<int>(m + 2, -1)); 
    ll ans = 0;
    if(arr[0] != 0){
        ans = solve(1,arr[0]);
    }else{
        for(int i = 1 ;i <= m ; ++i){
            ans = (ans  + solve(1 , i) ) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}

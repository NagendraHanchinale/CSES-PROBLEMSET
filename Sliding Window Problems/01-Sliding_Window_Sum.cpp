#include<bits/stdc++.h>
using namespace std;

int n , k;

void generator(vector<int> &arr , int x , int a , int b , int c){
    arr[0] = x;
    for(int i = 1 ; i < n ; ++i){
        arr[i] = (a * arr[i - 1] + b) % c;
    }
}

int main() {
    cin >> n >> k;
    vector<int> arr(n);
    int x , a , b , c;
    cin >> x >> a >> b >> c;

    generator(arr , x , a , b , c);

    int ans  = 0;
    for(int i = 0 ; i < k ; ++i)ans += arr[i];

    int xx = ans;
    for(int i = k ; i < n ; ++i){
        ans = ans - arr[i - k] + arr[i];
        xx ^= ans;
    }
    cout << xx << endl;
    return 0;
}
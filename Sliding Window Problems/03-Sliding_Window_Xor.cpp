#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, k;

void generator(vector<ll>& arr, ll x, ll a, ll b, ll c) {
    arr[0] = x;
    for (ll i = 1; i < n; ++i) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }
}

int main() {
    cin >> n >> k;
    vector<ll> arr(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    generator(arr, x, a, b, c);

    ll xx = 0;

    for(int i = 0 ; i < k ; ++i)xx ^= arr[i];

    ll ans = xx;

    for(int i = k ; i < n ; ++i){
        xx ^= arr[i - k];
        xx ^= arr[i];
        ans ^= xx;
    }

    cout << ans << endl;

    return 0;
}

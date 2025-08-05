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

    ll ans = 0;
    for (ll i = 0; i < k; ++i) ans += arr[i];

    ll xx = ans;
    for (ll i = k; i < n; ++i) {
        ans = ans - arr[i - k] + arr[i];
        xx ^= ans;
    }

    cout << xx << endl;
    return 0;
}

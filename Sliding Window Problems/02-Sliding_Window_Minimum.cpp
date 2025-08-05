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

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    int l = 0, r = 0;
    ll xx = 0;

    while (r < n) {
        q.push({arr[r], r});

        while ((r - l + 1) > k) {
            l++;
        }
        while (!q.empty() && q.top().second < l) {
            q.pop();
        }
        if ((r - l + 1) == k) {
            ll mini = q.top().first;
            xx ^= mini;
        }
        r++;
    }

    cout << xx << endl;
    return 0;
}

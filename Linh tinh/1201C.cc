#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const ll N = 2e5 + 10;
ll a[N];
ll n, k;

bool ok(ll x) {
    ll total = 0;
    for (ll i = n / 2; i < n; ++i) {
        if (x <= a[i]) break;
        total += (x - a[i]);
    }
 
    return k >= total;
}

signed main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin >> n >> k;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
 
    ll l = 1, r = 2000000000;
    for (ll i = 0; i <= 60; ++i) {
        ll m = l + (r - l) / 2;
        if (ok(m)) l = m + 1;
        else r = m;
    }
    cout << l - 1 << endl;
}
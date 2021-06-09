#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
ll n;
int t;

pair<ll, ll> fib(ll n) {
    if (n == 0) return {0, 1};

    auto p = fib(n >> 1);
    long long c = (1LL * p.first * (2 * p.second - p.first + MOD)) % MOD;
    long long d = (1LL * p.first * p.first + 1LL * p.second * p.second) % MOD;

    if (n & 1) return {d, (c + d) % MOD};
    else return {c, d};
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 0) cout << 0 << endl;
        else if (n == 1) cout << 2 << endl;
        else {
            cout << fib(n + 3).first << endl;
        }
    }
}
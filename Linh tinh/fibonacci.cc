#include "bits/stdc++.h"

using namespace std;

#define sqr(x) (x) * (x)

typedef long long ll;

const int MOD = 1e9 + 7;
ll n;

pair<ll, ll> fib(ll n) {
    if (n == 0) return {0, 1};

    auto p = fib(n >> 1);
    ll c = (p.first * (2 * p.second % MOD - p.first + MOD)) % MOD;
    ll d = (sqr(p.first) + sqr(p.second)) % MOD;

    if (n & 1) return {d, c + d};
    return {c, d};
}

int main() {
    cin >> n;
    cout << fib(n).first << endl;
}
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
int n, m, t;

pair<ll, ll> fib(int n) {
    if (n == 0) return {0, 1};

    auto p = fib(n >> 1);
    long long c = (p.first * (2 * p.second % MOD - p.first + MOD)) % MOD;
    long long d = (p.first * p.first + p.second * p.second) % MOD;

    if (n & 1) return {d, c + d};
    return {c, d};
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << (fib(m + 2).first % MOD - fib(n + 1).first % MOD + MOD) % MOD << endl;
    }
}
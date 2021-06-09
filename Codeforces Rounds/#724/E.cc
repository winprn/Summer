#include "bits/stdc++.h"

using namespace std;

const long long MOD = 1e9 + 7;
long long n, m, t;

long long fexp(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long cnt = 0;
        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                char x; cin >> x;
                if (x == '#') ++cnt;
            }
        }

        cout << fexp(2, cnt) - (cnt / (n * m)) << endl;
    }
}
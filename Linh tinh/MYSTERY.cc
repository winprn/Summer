#include "bits/stdc++.h"

using namespace std;

const long long MOD = 20122007;
long long n;

long long pw(long long a, long long b) {
    long long kq = 1;
    while (b) {
        if (b & 1) {
            kq *= a;
            kq %= MOD;
        }

        a *= a;
        a %= MOD;
        b >>= 1;
    }

    return kq;
}

int main() {
    freopen("i", "r", stdin);

    cin >> n;
    vector<long long> uoc;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            uoc.push_back(i);
            if (n / i != i) uoc.push_back(n / i);
        }
    }

    long long ans = 1;
    for (long long i : uoc) {
        ans *= (pw(3, i) - 1);
        ans %= MOD;
    }
    cout << ans;
}
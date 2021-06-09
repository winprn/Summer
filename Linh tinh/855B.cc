#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
long long dp0[N], dp1[N], dp2[N], a[N];
long long n, p, q, r;

int main() {
    freopen("i", "r", stdin);

    cin >> n >> p >> q >> r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp0[0] = a[0] * p;
    for (int i = 1; i < n; ++i) {
        dp0[i] = max(dp0[i - 1], a[i] * p);
    }

    dp1[0] = dp0[0] + a[0] * q;
    for (int i = 1; i < n; ++i) {
        dp1[i] = max(dp1[i - 1], dp0[i] + a[i] * q);
    }

    dp2[0] = dp1[0] + a[0] * r;
    for (int i = 1; i < n; ++i) {
        dp2[i] = max(dp2[i - 1], dp1[i] + a[i] * r);
    }
    cout << dp2[n - 1];
}
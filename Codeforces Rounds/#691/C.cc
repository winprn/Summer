#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
long long a[N];
int n, m;

long long _gcd(long long a, long long b) {
    if (b == 0) return a;

    return _gcd(b, a % b);
}

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long gcd = 0;
    for (int i = 1; i < n; ++i) {
        gcd = _gcd(gcd, a[i] - a[i - 1]);
    }
    for (int i = 0; i < m; ++i) {
        long long x; cin >> x;
        cout << _gcd(gcd, a[0] + x) << ' ';
    }
}
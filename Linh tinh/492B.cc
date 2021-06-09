#include "bits/stdc++.h"

using namespace std;

const double eps = 1e-9;
const int N = 1e3 + 10;
int a[N];
int n, l;

bool ok(double x) {
    for (int i = 0; i < n; ++i) {
        if (a[i] + 2 * x < a[i + 1]) return 0;
    }

    return (a[0] - x <= 0 && a[n - 1] + x >= l);
}

int main() {
    cout.precision(10);
    cout << fixed;
    freopen("i", "r", stdin);

    cin >> n >> l;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    double l = 0, r = 1e9 + 7;
    for (int i = 0; i <= 63; ++i) {
        double m = (l + r) / 2;
        if (ok(m)) r = m;
        else l = m;
    }
    cout << r << endl; 
}
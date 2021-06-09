#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        int cnt = 1, mx = -1e9 + 7, mn = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            if (min(mn, abs(a[i] - a[i - 1])) >= max(mx, a[i])) {
                ++cnt;
                mx = max(mx, a[i]);
                mn = min(mn, abs(a[i]  - a[i - 1]));
            } else break;
        }
        cout << cnt << endl;
    }
}
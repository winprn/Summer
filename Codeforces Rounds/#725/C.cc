#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, R, L, t;

int bs1(int x, int id) {
    int l = id + 1, r = n;
    for (int i = 0; i <= 30; ++i) {
        int m = l + (r - l) / 2;
        if (m == id) r = m;
        if (a[m] + x < L) l = m;
        else r = m;
    }

    return r;
}

int bs2(int x, int id) {
    int l = id + 1, r = n;
    for (int i = 0; i <= 30; ++i) {
        int m = l + (r - l) / 2;
        if (m == id) l = m;
        if (a[m] + x > R) r = m;
        else l = m;
    }

    return l;
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> L >> R;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);

        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            auto it = lower_bound(a + i + 1, a + 1 + n, L - a[i]) - a;
            auto it2 = upper_bound(a + i + 1, a + 1 + n, R - a[i]) - a;
            --it2;
            if (a[it2] != 0 && a[it] != 0 && a[it] + a[i] <= R && a[it2] + a[i] <= R) 
                ans += (it2 - it + 1);
        }
        cout << ans << endl;
    }
}
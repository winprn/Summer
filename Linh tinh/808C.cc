#include "bits/stdc++.h"

using namespace std;

pair<int, int> a[105];
int b[105];
int n, w;

int main() {
    freopen("i", "r", stdin);

    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, greater<pair<int, int>>());

    bool ok = 1;
    for (int i = 0; i < n && ok; ++i) {
        int cur = (a[i].first + 1) / 2;
        if (w - cur < 0) ok = 0;
        b[a[i].second] += cur;
        w -= cur;
    }

    if (!ok) cout << "-1";
    else {
        for (int i = 0; i < n && w > 0; ++i) {
            int tmp = min(w, a[i].first - b[a[i].second]);
            b[a[i].second] += tmp;
            w -= tmp;
        }

        for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    }
}
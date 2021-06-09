#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, sum = 0, len = 0, idx = -1;

int main() {
    freopen("i", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int mx = *max_element(a, a + n);

    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        while (i < n && a[i] == mx) ++tmp, ++i;

        len = max(tmp, len);
    }
    cout << len;
}
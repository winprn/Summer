#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
long long a[N], dp[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            dp[i] = a[i];
        }

        for (int i = 1; i <= n; ++i) {
            if (i + a[i] <= n) {
                dp[i + a[i]] = max(dp[i + a[i]], dp[i] + a[i + a[i]]);
            }
        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }
}
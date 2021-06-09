#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N], dp[N];
int n, k;

int main() {
    freopen("i", "r", stdin);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = -1e9;
    }

    for (int i = 1; i <= min(n, k); ++i) dp[i] = a[i];
    
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= min(n, i + k); ++j) {
            dp[j] = max(dp[j], dp[i] + a[j]);
        }
    }
    
    // for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
    // cout << endl;
    cout << *max_element(dp + 1, dp + n + 1);
}
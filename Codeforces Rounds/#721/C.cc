#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
long long dp[N];
int a[N];
int n, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            dp[i] = 0;
        }

        map<long long, long long> mp;
        mp[a[0]] = 1;
        long long ans = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];

            if (mp.count(a[i])) dp[i] += mp[a[i]];
            mp[a[i]] += (i + 1);

            ans += dp[i];
        }
        cout << ans << endl;
    }
}
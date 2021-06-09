#include "bits/stdc++.h"

using namespace std;

const int MOD = 998244353;
const int N = 1e6 + 10;
int dp[N];
int n;

int main() {
    freopen("i", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            dp[j]++;
        }
    }
    long long cur;
    dp[0] = cur = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (dp[i] + cur) % MOD;
        cur = (cur + dp[i]) % MOD;
    }
    cout << dp[n];
}
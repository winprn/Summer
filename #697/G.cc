#include <bits/stdc++.h>

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int N = 2e5 + 10;
int cnt[N], dp[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        ms(cnt, 0), ms(dp, 0);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
        }

        for (int i = 1; i < N; ++i) {
            dp[i] += cnt[i];
            for (int j = i * 2; j < N; j += i) {
                dp[j] = max(dp[j], dp[i]);
            }
        }
        cout << n - *max_element(dp, dp + N) << endl;
    }
}
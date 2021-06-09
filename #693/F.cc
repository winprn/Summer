#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second

typedef long long ll;

const int N = 2e5 + 10;
pair<ll, ll> a[N];
bool bad[N + 10][2];
bool dp[N + 10][4];
ll n, m, t;

ll compress(ll a, ll b) {
    if (a - b < 4) return 0;
    ll dis = 4;
    if (a % 2 != b % 2) --dis;
    dis = (a - b) - dis;

    return dis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof dp);
        memset(bad, 0, sizeof bad);
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            cin >> a[i].se >> a[i].fi;
        }
        sort(a, a + m);

        ll off = compress(a[0].fi, 1);
        for (int i = 0; i < m; ++i) {
            --a[i].se;
            a[i].fi -= off;

            if (i > 0) {
                ll tmp = compress(a[i].fi, a[i - 1].fi);
                a[i].fi -= tmp;
                off += tmp;
            }
        }
        n -= off;
        n -= compress(n, a[m - 1].fi);

        int k = n + 5;
        for (int i = 0; i < m; ++i) {
            assert(a[i].fi >= 0 && a[i].se >= 0);
            bad[a[i].fi][a[i].se] = 1;
        }
        dp[0][3] = 1;

        for (int i = 0; i < k; ++i) {
            if (dp[i][3]) {
                int tmp = bad[i + 1][0] + 2 * bad[i + 1][1];
                dp[i + 1][tmp] = 1;
            }

            if (dp[i][2] && !bad[i + 1][0]) {
                int tmp = 1;
                if (bad[i + 1][1]) tmp += 2;
                dp[i + 1][tmp] = 1;
            }

            if (dp[i][1] && !bad[i + 1][1]) {
                int tmp = 2;
                if (bad[i + 1][0]) ++tmp;
                dp[i + 1][tmp] = 1;
            }

            if (dp[i][0] && !bad[i + 1][1] && !bad[i + 1][0]) dp[i + 1][3] = 1;
            if (dp[i][3] && !bad[i + 1][1] && !bad[i + 1][0]) dp[i + 1][3] = 1;
        }
        if (dp[n][3]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
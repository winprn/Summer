#include <bits/stdc++.h>

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int MOD = 1e9 + 7;
const int N = 1e3 + 10;
int cnt[N];
int n, k, t;

int fpow(int a, int b) {
    int kq = 1;
    while (b) {
        if (b % 2 == 0) {a = a * 1LL * a % MOD; b >>= 1;}
        else {
            kq = kq * 1LL * a % MOD;
            --b;
        }
    }

    return kq;
}

int fact(int n) {
    int kq = 1;
    for (int i = 1; i <= n; ++i) {
        kq = kq * 1LL * i % MOD;
    }

    return kq;
}

int solve(int n, int k) {
    return (fact(n) * 1LL * fpow(fact(k), MOD - 2) % MOD * 1LL * fpow(fact(n - k), MOD - 2) % MOD);
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        ms(cnt, 0);
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
        }

        int ans = 1;
        for (int i = n; i >= 1; --i) {
            if (cnt[i] >= k) {
                ans = solve(cnt[i], k);
                break;
            } else k -= cnt[i];
        }
        cout << ans << endl;
    }
}
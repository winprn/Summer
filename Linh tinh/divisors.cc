#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int MX = 1e3 + 10;
vector<int> primes;
bitset<(int) 1e3 + 20> pr;
int n, k;

void sieve() {
    pr.set();
    pr[0] = pr[1] = 0;
    for (int i = 4; i <= MX; i += 2) pr[i] = 0;
    for (int i = 3; i * i <= MX; i += 2) {
        if (pr[i]) {
            for (int j = i * i; j <= MX; j += i) pr[j] = 0;
        }
    }
    for (int i = 2; i <= MX; ++i) {
        if (pr[i]) primes.pb(i);
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> kq;
    for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= x; ++i) {
        int cur = primes[i], cnt = 0;
        while (x % cur == 0) {
            x /= cur;
            ++cnt;
        }

        if (cnt > 0) kq.pb({cur, cnt});
    }

    if (x != 1) kq.pb({x, 1});
    return kq;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while (cin >> n >> k) {
        unordered_map<int, int> fact;
        for (int i = 2; i <= n; ++i) {
            auto tmp = factorize(i);
            for (auto j : tmp) fact[j.fi] += j.se;
        }

        for (int i = 2; i <= k; ++i) {
            auto tmp = factorize(i);
            for (auto j : tmp) fact[j.fi] -= j.se;
        }
        for (int i = 2; i <= n - k; ++i) {
            auto tmp = factorize(i);
            for (auto j : tmp) fact[j.fi] -= j.se;
        }

        ll ans = 1;
        for (auto i : fact) {
            if (i.se != 0) ans *= (i.se + 1);
        }
        cout << ans << endl;
    }
}
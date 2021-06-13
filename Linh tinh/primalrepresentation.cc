#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N = 1e7 + 9;
vector<ll> primes;
bitset<(int)1e8> pr;
ll n;

void sieve() {
    pr.set();
    pr[0] = pr[1] = 0;
    for (ll i = 2; i <= N; ++i) {
        if (pr[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= N; j += i) pr[j] = 0;
        }
    }
}

vector<pair<ll, int>> get(ll x) {
    vector<pair<ll, int>> kq;
    for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= x; ++i) {
        ll cur = primes[i], cnt = 0;
        while (x % primes[i] == 0) {
            ++cnt;
            x /= primes[i];
        }

        if (cnt) kq.pb({cur, cnt});
    }

    if (x != 1) kq.pb({x, 1});
    return kq;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while (cin >> n) {
        if (n < 0) cout << "-1 ";
        n = abs(n);
        auto p = get(n);

        for (auto i : p) {
            if (i.se == 1) cout << i.fi << ' ';
            else cout << i.fi << '^' << i.se << ' ';
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define pb push_back
#define sqr(x) (x) * (x)

typedef long long ll;

const int MX = 1e7 + 5;
vector<ll> primes;
bitset<100000010> pr;
ll n;

void sieve() {
    pr.set();
    pr[0] = pr[1] = 0;
    for (ll i = 2; i <= MX; ++i) {
        if (pr[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= MX; j += i) {
                pr[j] = 0;
            }
        }
    }
}

bool check(ll x) {
    if (x == 0 || x == 1) return 0;
    for (ll i : primes) {
        if (sqr(i) > x) break;
        if (x % i == 0) return 0;
    }

    return 1;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while (cin >> n, n) {
        bool ok = check(n);

        ll ans = 2 * n;
        while (!check(ans)) ++ans;

        cout << ans;
        if (!ok) cout << " (" << n << " is not prime)";
        cout << endl;
    }
}
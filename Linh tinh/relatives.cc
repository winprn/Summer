#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int MX = 1e8;
vector<ll> primes;
bitset<(int) 1e8 + 10> pr;
ll n;

void sieve() {
    pr.set();
    pr[0] = pr[1] = 0;
    primes.pb(2);
    for (ll i = 4; i <= MX; i += 2) pr[i] = 0;
    for (ll i = 3; i <= MX; i += 2) {
        if (pr[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= MX; j += (i * 2)) pr[j] = 0;
        }
    }
    //for (int i = 2; i <= MX; ++i) primes.pb(i);
}

long long phi(ll x) {
    ll ans = x;
    for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= x; ++i) {
        if (x % primes[i] == 0) ans -= ans / primes[i];
        while (x % primes[i] == 0) x /= primes[i];
    }

    if (x != 1) ans -= ans / x;
    return ans;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while (cin >> n, n) {
        cout << phi(n) << endl;
    }
}
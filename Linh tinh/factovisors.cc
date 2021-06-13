#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define fi first
#define se second
#define sqr(x) (x) * (x)

typedef long long ll;

const int N = 1e7;
vector<ll> primes;
bitset<10000010> pr;
long long n, m;

void sieve() {
    pr.set();
    //pr[0] = pr[1] = 0;
    for (ll i = 2; i <= N; ++i) {
        if (pr[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= N; j += i) pr[j] = 0;
        }
    }
}

vector<pair<ll, int>> factorize(ll x) {
    vector<pair<ll, int>> kq;
    for (int i = 0; i < (int) primes.size() && sqr(primes[i]) <= x; ++i) {
        ll cur = primes[i], cnt = 0;
        while (x % primes[i] == 0) {
            ++cnt;
            x /= primes[i];
        }

        if (cnt != 0) kq.pb({cur, cnt});
    }

    if (x > 1) kq.pb({x, 1});
    return kq;
}

int check(ll x) {
    int sum = 0, cur = x;
    for (int i = 1; cur <= n; ++i) {
        sum += n / cur;
        cur *= x;
    }

    return sum;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while (cin >> n >> m) {
        bool ok = 1;
        if (m == 0) ok = 0;
        else if (m <= n) ok = 1;
        else {
            auto p = factorize(m);

            //for (auto i : p) cout << i.fi << ' ' << i.se << endl;
            for (auto i : p) {
                if (check(i.fi) < i.se) {
                    ok = 0;
                    break;
                }
            }
        }

        if (ok) cout << m << " divides " << n << '!' << endl;
        else cout << m << " does not divide " << n << '!' << endl;
    }
}
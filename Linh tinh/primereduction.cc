#include <bits/stdc++.h>

using namespace std;

#define pb push_back
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

bool isPrime(int n) {
    if (n <= N) return pr[n];
    for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) return 0;
    }

    return 1;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while (cin >> n, n != 4) {
        int cnt = 1;
        while (!isPrime(n) && n >= 2) {
            int tmp = 0;
            for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= n; ++i) {
                while (n % primes[i] == 0) {
                    tmp += primes[i];
                    n /= primes[i];
                }
            }

            if (n != 1) tmp += n;
            n = tmp;
            ++cnt;
        }

        cout << n << ' ' << cnt << endl;
    }
}
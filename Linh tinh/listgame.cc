#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int MX = 1e7 + 9;
vector<ll> primes;
bitset<(int) 1e8 + 10> pr;
ll n;

void sieve() {
    pr.set();
    pr[0] = pr[1] = 0;
    for (ll i = 2; i <= MX; ++i) {
        if (pr[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= MX; j += i) pr[j] = 0;
        }
    }
}

int numPF() {
    int ans = 0;
    for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= n; ++i) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            ++ans;
        }
    }

    return ans + (n != 1);
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    cin >> n;
    cout << numPF() << endl;
}
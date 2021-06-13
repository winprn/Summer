#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define pb push_back

typedef long long ll;

const int MX = 1e8 + 10;
vector<int> primes;
bitset<(int)1e8 + 20> pr;
int n, q;

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

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    cin >> n >> q;
    cout << upper_bound(primes.begin(), primes.end(), n) - primes.begin() << endl;
    while (q--) {
        int x; cin >> x;
        cout << pr[x] << endl;
    }
}
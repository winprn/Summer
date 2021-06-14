#include "bits/stdc++.h"

using namespace std;

#define pb push_back

typedef long long ll;

const int N = 1e7 + 9;
vector<ll> primes;
bitset<(int) 1e8> pr;
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

ll sumDiv(ll n) {
	ll kq = 1;
	for (int i = 0; i < (int) primes.size() && primes[i] * primes[i] <= n; ++i) {
		ll cur = primes[i], total = 1;
		while (n % primes[i] == 0) {
			n /= primes[i];
			total += cur;
			cur *= primes[i];
		}
		kq *= total;
	}

	if (n != 1) kq *= (n + 1);
	return kq;
}

int main() {
	freopen("i", "r", stdin);

	sieve();
	while (cin >> n) {
		cout << n;
		ll sum = sumDiv(n) - n;
		if (sum - n == 0) cout << " perfect";		
		else if (sum - n <= 2 && sum - n >= -2) cout << " almost perfect";
		else cout << " not perfect";
		cout << endl;
	}
}
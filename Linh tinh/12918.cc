#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll n, m;
int t;

ll sum(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n == 1) {
            if (m == 1) cout << 1 << endl;
            else cout << m - 1 << endl;
        } else {
            cout << sum(m - 1) - sum(m - n - 1) << endl;
        }
    }
}
#include "bits/stdc++.h"

using namespace std;

#define sqr(x) (x) * (x)

typedef long long ll;

ll n;
int t;

bool isSquare(long long x) {
    return sqr(ceil(sqrt(x))) == x;
}

ll get_lower(ll x) {
    int i;
    for (i = 0; i <= x; ++i) {
        if (sqr(i) > x) break;
    }

    return sqr(i - 1);
}

ll get_upper(ll x) {
    int i;
    for (i = 0; i <= x; ++i) {
        if (sqr(i) > x) break;
    }

    return sqr(i);
}

int main() {
    freopen("i", "r", stdin);

    while (cin >> n, n) {
        if (isSquare(n)) {
            if (n & 1) cout << 1 << ' ' << sqrt(n) << endl;
            else cout << sqrt(n) << ' ' << 1 << endl; 
        } else {
            ll l = get_lower(n), r = get_upper(n);
            if (n - l < r - n) {
                ll diff = n - l, i, j;
                if (l & 1) {
                    i = 1, j = sqrt(l);
                    cout << 1 + diff - 1 << ' ' << j + 1 << endl;
                } else {
                    i = sqrt(l), j = 1;
                    cout << i + 1 << ' ' << j + diff - 1 << endl;
                }
            } else {
                ll diff = r - n, i, j;
                if (r & 1) {
                    i = 1, j = sqrt(r);
                    cout << i + diff << ' ' << j << endl;
                } else {
                    i = sqrt(r), j = 1;
                    cout << i << ' ' << j + diff << endl;
                }
            }
        }
    }
}
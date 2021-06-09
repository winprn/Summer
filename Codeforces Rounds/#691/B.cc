#include "bits/stdc++.h"

using namespace std;

#define sqr(x) (x) * (x)

int main() {
    freopen("i", "r", stdin);

    long long n; cin >> n;
    if (n % 2 == 0) cout << sqr(n / 2 + 1);
    else cout << 2 * (n / 2 + 1) * (n / 2 + 2);
}
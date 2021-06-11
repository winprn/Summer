#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

ll a, b, n, m;
int t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> a >> b >> n >> m;
        ll c = a, d = b;
        ll ans = 0, ans2 = 0;
        int tmp = min(a / n, b / m);
        ans += tmp;
        a -= n * tmp, b -= m * tmp;
        tmp = min(a / m, b / n);
        ans += tmp;

        int tmp2 = min(a / m, b / n);
        ans2 += tmp2;
        a -= tmp * m, b -= tmp * n;
        tmp2 = min(a / n, b / m);
        ans2 += tmp2;

        cout << max(ans, ans2) << endl;
    }
}
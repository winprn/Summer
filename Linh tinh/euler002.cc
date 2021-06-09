#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll MX = 4e16 + 10;
const int N = 505;
ll f[N];
ll ans, n;
int t;

int main() {
    freopen("i", "r", stdin);

    f[0] = 1, f[1] = 2;
    for (int i = 2; f[i - 1] <= MX; ++i) {
        f[i] = f[i - 2] + f[i - 1];
    }

    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 0; f[i] <= n; ++i) {
            if (!(f[i] & 1)) ans += f[i];
        }
        cout << ans << endl;
    }
}
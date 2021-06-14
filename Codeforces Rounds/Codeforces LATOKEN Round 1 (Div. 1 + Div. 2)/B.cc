#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N = 4e5 + 10;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll ans = 0;
        if (n == 1) cout << a[0] << endl;
        else {
            for (int i = 0; i < n; ++i) {
                if (i == 0) {
                    if (a[i] > a[i + 1]) {
                        //cout << a[i + 1] << endl;
                        ans += a[i] - a[i + 1];
                        ans += a[i + 1];
                    } else ans += a[i];
                }
                if (i == n - 1) {
                    if (a[i] > a[i - 1]) {
                        ans += a[i] - a[i - 1];
                        ans += a[i - 1];
                    } else ans += a[i];
                }
                if (i > 0 && i < n - 1) {
                    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                        int tmp = max(a[i - 1], a[i + 1]), tmp2 = min(a[i - 1], a[i + 1]);
                        ans += a[i] - tmp;
                        ans += tmp - tmp2;
                    } else if (a[i] > a[i - 1]) ans += a[i] - a[i - 1];
                    else if (a[i] > a[i + 1]) ans += a[i] - a[i + 1];
                }
            }

            cout << ans << endl;
        }
       
    }
}
#include "bits/stdc++.h"

using namespace std;

const int N = 3e4 + 10;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        int ans = n + 3;
        for (int j = 0; j < n; ++j) {
            if (sum % (n - j) != 0) continue ;
            long long tmp = sum / (n - j), cursum = 0;
            bool ok = 1;
            for (int i = 0; i < n; ++i) {
                cursum += a[i];
                if (cursum == tmp) cursum = 0;
                else if (cursum > tmp) {
                    ok = 0;
                    break;
                }
            }

            if (ok) ans = min(ans, j);
        }
        assert(ans != n + 3);
        cout << ans << endl;
    }
}
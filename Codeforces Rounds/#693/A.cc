#include "bits/stdc++.h"

using namespace std;

int n, m, k, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int cnt1 = 0, cnt2 = 0;
        while (n % 2 == 0) {
            n /= 2;
            ++cnt1;
        }
        while (m % 2 == 0) {
            m /= 2;
            ++cnt2;
        }

        if (1LL * (1 << cnt1) * (1 << cnt2) >= k) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
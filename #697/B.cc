#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = 0;
        for (int i = 0; i <= 500; ++i) {
            int tmp = 2020 * i;
            if (tmp > n) break;
            if ((n - tmp) % 2021 == 0) {
                ok = 1;
                break;
            }
        }

        if (ok) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
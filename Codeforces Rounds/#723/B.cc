#include "bits/stdc++.h"

using namespace std;

int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = 0;
        for (int i = 0; i <= 20; ++i) {
            if (n % 11 == 0) {
                ok = 1;
                break;
            }
            n -= 111;
            if (n < 0) break;
        }

        if (ok) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
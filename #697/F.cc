#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int a[N][N], b[N][N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char x; cin >> x;
                a[i][j] = x - '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char x; cin >> x;
                b[i][j] = x - '0';
            }
        }

        for (int j = 0; j < n; ++j) {
            if (a[0][j] != b[0][j]) {
                for (int i = 0; i < n; ++i) {
                    a[i][j] ^= 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i][0] != b[i][0]) {
                for (int j = 0; j < n; ++j) {
                    a[i][j] ^= 1;
                }
            }
        }

        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != b[i][j]) {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}
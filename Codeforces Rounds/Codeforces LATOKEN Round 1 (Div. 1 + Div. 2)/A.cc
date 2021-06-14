#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const char mau[2] = {'R', 'W'};
int r[200], w[200];
int n, m, t;

bool ok(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(r, 0, sizeof r), memset(w, 0, sizeof w);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x; cin >> x;
                if (x == 'W') w[i + j & 1] = 1;
                else if (x == 'R') r[i + j & 1] = 1;
            }
        }

        bool ok = r[0] || w[1], ok2 = r[1] || w[0];
        if (ok && ok2) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << mau[i + j + ok2 & 1];
                }
                cout << endl;
            }
        }
    }
}
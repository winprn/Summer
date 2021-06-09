#include "bits/stdc++.h"

using namespace std;

const int N = 3e4 + 10;
int a[N];
int n, m;

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(a, a + m);

    if (a[0] == 1 || a[m - 1] == n) cout << "NO";
    else {
        bool ok = 1;
        for (int i = 0; i < m - 2; ++i) {
            if (a[i] + 1 == a[i + 1] && a[i] + 2 == a[i + 2]) {
                ok = 0;
                break;
            }
        }

        if (ok) cout << "YES";
        else cout << "NO";
    }
    cout << endl;
}
#include "bits/stdc++.h"

using namespace std;

const int N = 55;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2 * n; ++i) cin >> a[i];
        sort(a, a + 2 * n);

        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ' << a[i + n] << ' ';
        }
        cout << endl;
    }
}
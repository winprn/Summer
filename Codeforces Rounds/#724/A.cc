#include "bits/stdc++.h"

using namespace std;

const int N = 1e2 + 10;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] < 0) ok = 0;
        }

        if (!ok) cout << "nO";
        else {
            cout << "yEs" << endl;
            int mx = *max_element(a, a + n);
            cout << mx + 1 << endl;
            for (int i = 0; i <= mx; ++i) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
}
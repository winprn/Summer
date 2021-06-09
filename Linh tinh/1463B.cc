#include "bits/stdc++.h"

using namespace std;

int a[55], b[55];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        memset(b, 0, sizeof b);
        cin >> n;
        long long sum = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) b[i] = a[i];
            else b[i] = 1;

            sum2 += abs(a[i] - b[i]);
        }

        if (2 * sum2 <= sum) {
            for (int i = 0; i < n; ++i) {
                cout << b[i] << ' ';
            }
            cout << endl;
        } else {
            sum2 = 0;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 1) b[i] = a[i];
                else b[i] = 1;

                sum2 += abs(a[i] - b[i]);
            }
            assert(2 * sum2 <= sum);
            
            for (int i = 0; i < n; ++i) {
                cout << b[i] << ' ';
            }
            cout << endl;
        }
    }
}
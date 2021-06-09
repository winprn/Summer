#include "bits/stdc++.h"

using namespace std;

long long n, t;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        long long mx = -1, sum = 0;
        for (int i = 0; i < n; ++i) {
            long long x; cin >> x;
            mx = max(mx, x);
            sum += x;
        }

        long long tmp = max((sum + n - 2) / (n - 1), mx);
        cout << (n - 1) * tmp - sum << endl;
    }
}
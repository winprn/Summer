#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, x, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        vector<int> b;
        long long sum = 0, sum2 = 0;
        cin >> n >> x;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += (a[i] + x - 1) / x;
            sum2 += a[i];
        }

        cout << (sum2 + x - 1) / x << ' ' << sum << endl;
    }
}
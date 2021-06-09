#include "bits/stdc++.h"

using namespace std;

int n, t, x;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = 1;
        }
        
        long long sum = 0;
        bool ok = 1;
        for (int i = 0; i < (int) a.size(); ++i) {
            sum += a[i].first * a[i].second;
            if (a[i].first % x != 0) ok = 0;
            if (ok) a.push_back({a[i].first / x, x * a[i].second});
        }
        cout << sum << endl;
    }
}
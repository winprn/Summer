#include "bits/stdc++.h"

using namespace std;

int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        int mn = 1e9, mx = -1;
        int id1 = -1, id2 = -1;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if (x > mx) {
                mx = x;
                id1 = i;
            }

            if (x < mn) {
                mn = x;
                id2 = i;
            }
        }

        //cout << id1 << ' ' << id2 << endl;
        int ans1 = min(id1, n - id1 + 1), ans2 = min(id2, n - id2 + 1);
        int ans = min({ans1 + ans2, min(id1, n - id1 + 1) + abs(id1 - id2), min(id2, n - id2 + 1) + abs(id1 - id2)});
        cout << ans << endl;
    }
}
#include "bits/stdc++.h"

using namespace std;

bool col[60], row[60];
int n, m, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        memset(col, 0, sizeof col);
        memset(row, 0, sizeof row);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x; cin >> x;
                if (x == 1) row[i] = col[j] = 1;
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) cnt1 += !row[i];
        for (int i = 0; i < m; ++i) cnt2 += !col[i];

        //cout << cnt1 << ' ' << cnt2 << endl;
        if (min(cnt1, cnt2) & 1) cout << "Ashish";
        else cout << "Vivek";
        cout << endl;
    }
}
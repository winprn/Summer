#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 1) cout << 9;
        else if (n == 2) cout << 98;
        else if (n == 3) cout << 989;
        else {
            vector<int> kq = {0, 9, 8, 9};
            int cnt = 0;
            for (int i = 4; i <= n; ++i) {
                if (cnt == 10) cnt = 0;
                kq.push_back(cnt);
                ++cnt;
            }
            for (int i = 1; i <= n; ++i) cout << kq[i];
        }
        cout << endl;
    }
}
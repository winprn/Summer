#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
vector<pair<int, int>> op;
int n, t, ans, mx, idx;

vector<int> get(int x, vector<int> a) {
    multiset<int> ms;
    for (auto i : a) ms.insert(i);

    vector<int> kq;
    for (int i = 0; i < n; ++i) {
        auto it = ms.end();
        it--;
        int y = x - *it;
        ms.erase(it);
        it = ms.find(y);

        if (it == ms.end()) return {};

        kq.push_back(x - y);
        kq.push_back(y);
        x = max(y, x - y);
        ms.erase(it);
    }

    return kq;
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        mx = idx = -1;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        // cout << a[2 * n - 1] << endl;

        bool ok = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int cur = a[i] + a[2 * n - 1];
            vector<int> ans = get(cur, a);

            if (ans.size()) {
                ok = 1;
                cout << "YES" << endl;
                cout << cur << endl;
                for (int j = 0; j < n; ++j) {
                    cout << ans[2 * j] << ' ' << ans[2 * j + 1] << endl;
                }
            }
        }

        if (!ok) cout << "NO" << endl;
    }
}
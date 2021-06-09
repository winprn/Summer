#include "bits/stdc++.h"

using namespace std;

const int N = 3e5 + 10;
pair<int, int> price[N];
int a[N];
int n, m, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> price[i].first;
            price[i].second = i;
        }
        sort(a, a + n, greater<int>());
        sort(price, price + m);

        long long ans = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur == m) ans += price[a[i]].first;
            else {
                if (price[cur].first <= price[a[cur]].first && price[cur].second <= i) {
                    ans += price[cur].first;
                    ++cur;
                } else ans += price[a[i]].first;
            }
        }
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int N = 2e5 + 10;
vector<int> pq, pq2;
int a[N], b[N], p[N], p2[N];
int n, m, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        ms(p, 0), ms(p2, 0);
        pq.clear(), pq2.clear();
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        for (int i = 0; i < n; ++i) {
            if (b[i] == 2) pq2.push_back(a[i]);
            else pq.push_back(a[i]);
        }
        sort(pq.rbegin(), pq.rend()), sort(pq2.rbegin(), pq2.rend());
        const int sze = (int) pq.size(), sze2 = (int) pq2.size();

        if (sze) p[1] = pq[0];
        if (sze2) p2[1] = pq2[0];
        for (int i = 2; i <= sze; ++i) p[i] = p[i - 1] + pq[i - 1];
        for (int i = 2; i <= sze2; ++i) p2[i] = p2[i - 1] + pq2[i - 1];

        int ans = INT_MAX, j = sze2;
        for (int i = 1; i <= sze; ++i) {
            if (p[i] >= m) {ans = min(ans, i); break;}
        }
        for (int i = 1; i <= sze2; ++i) {
            if (p2[i] >= m) {ans = min(ans, i * 2); break;}
        }
        for (int i = 1; i <= sze; ++i) {
            while (p[i] + p2[j] >= m && j > 0) --j;
            // cout << i << ' ' << j << endl;
            // cout << p[i] << ' ' << p2[j] << endl;

            if (p[i] + p2[j] >= m) ans = min(ans, i + 2 * j);
            else if (j < sze2 && p[i] + p2[j + 1] >= m) ans = min(ans, i + 2 * (j + 1));
        }
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
}
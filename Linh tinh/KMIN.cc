#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second

const int N = 5e4 + 10;
int a[N], b[N], nxt[N];
int n, m, k;

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n), sort(b, b + m);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({a[i] + b[0], i});
    }

    while (k--) {
        cout << pq.top().fi << endl;
        int cur = pq.top().se;
        pq.pop();

        if (nxt[cur] + 1 < m) {
            nxt[cur]++;
            pq.push({a[cur] + b[nxt[cur]], cur});
        }
    }
}
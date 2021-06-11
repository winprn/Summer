#include "bits/stdc++.h"

using namespace std;

int c[505][505], f[505][505], trace[505];
int n, m, t, k, ans = 0;

bool bfs() {
    memset(trace, -1, sizeof trace);
    queue<int> q;
    q.push(1);
    trace[1] = n + 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v) {
            if (trace[v] == -1 && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == n) return 1;
                q.push(v);
            }
        }
    }

    return 0;
}

void inc() {
    int delta = 1e9, u, v = n;
    do {
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    } while (v != 1);
    ans += delta;

    v = n;
    do {
        u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    } while (v != 1);
}

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m >> t;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (t == 1) {
            c[u][v] = c[v][u] = 1;
        } else {
            c[u][u + n] = 1;
            c[v][v + n] = 1;
            c[u + n][v] = 1;
            c[v + n][u] = 1;
        }
    }  
    if (t == 2) {
        cin >> k;
        for (int i = 0; i < k; ++i) {
            int u; cin >> u;
            c[u][u + n] = 0;
        }
        c[1][1 + n] = 1e9;
        c[n][n + n] = 1e9;
        n = 2 * n;

        while (bfs()) inc();
        cout << ans << endl;
    } else {
        while (bfs()) inc();
        cout << ans << endl;
    }
}
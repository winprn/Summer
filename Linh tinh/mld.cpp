#include "bits/stdc++.h"

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

int c[2005][2005], f[2005][2005], trace[2005];
bool mark[1005];
int n, m, q, ans = 0, ans2 = 0;

bool bfs() {
    ms(trace, -1);
    queue<int> q;
    q.push(0);
    trace[0] = n + 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (trace[v] == -1 && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == n - 1) return 1;
                q.push(v);
            }
        }
    }

    return 0;
}

bool bfs2(int t) {
    ms(trace, -1);
    queue<int> q;
    q.push(0);
    trace[0] = 2 * n + 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < 2 * n + 1; ++v) {
            if (trace[v] == -1 && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == t) return 1;
                q.push(v);
            }
        }
    }

    return 0;
}

void inc(int &res, int t) {
    int delta = 1e9, u, v;
    v = t;
    do {
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    } while (v != 0);
    res += delta;

    v = t;
    do {
        u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    } while (v != 0);
}

int main() {
    freopen("i", "r", stdin);

    cin >> m >> n >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w, c[v][u] = w;
    }
    for (int i = 0; i < q; ++i) {
        int u; cin >> u;
        assert(u != 0);
        mark[u] = 1;
    }

    while(bfs()) inc(ans, n - 1);
    for (int i = 0; i < n; ++i) {
        if (mark[i] || i == 0) continue ;
        c[i][i + n] = 1;
        for (int j = 0; j < n; ++j) {
            if (mark[j] && c[i][j] > 0) {
                c[i + n][j] = c[i][j];
                c[i][j] = 0;
            }
        }
    }

    ms(f, 0);
    for (int i = 0; i < n; ++i) {
        if (mark[i]) {
            while (bfs2(i)) inc(ans2, i);
        }
    }
    cout << ans << endl << ans2 << endl;
}
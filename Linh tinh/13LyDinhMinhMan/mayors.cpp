#include "bits/stdc++.h"

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int N = 1005;
vector<int> adj[N];
int color[N], num[N][4], depth[N];
bool ok;
int n, m;

void undo(int d) {
    for (int i = 1; i <= n; ++i) {
        if (depth[i] >= d) {
            depth[i] = -1;
            color[i] = 0;
        }
        for (int j = 1; j <= 3; ++j) {
            if (num[i][j] >= d) {
                num[i][j] = 0;
                ++num[i][0];
            }
        }
    }
}

int getMin() {
    int u = -1;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (u == -1) u = i;
            if (num[u][0] > num[i][0]) u = i;
        }
    }

    return u;
}

void update(int u, int mau, int d) {
    for (int v : adj[u]) {
        if (color[v] == 0 && num[v][mau] == 0) {
            num[v][mau] = d;
            --num[v][0];
        }
    }
}

void dfs(int u, int mau, int d) {
    color[u] = mau;
    depth[u] = d;

    update(u, mau, d);
    if (d == n) {
        ok = 1;
        return ;
    }

    int mn = getMin();
    for (int i = 1; i <= 3; ++i) {
        if (num[mn][i] == 0) {
            dfs(mn, i, d + 1);
            if (ok) return ;
        }
    }

    undo(d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mayors.inp", "r", stdin);
    freopen("mayors.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        color[i] = 0, depth[i] = 0;
        num[i][1] = num[i][2] = num[i][3] = 0;
        num[i][0] = 3;
    }
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        assert(u <= n && v <= n);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ok = 0;

    dfs(1, 1, 1);
    if (!ok) cout << "-1";
    else {
        cout << "1" << endl;
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 1) cout << 'B';
            else if (color[i] == 2) cout << 'G';
            else cout << 'R';
        }
    }
    cout << endl;
}

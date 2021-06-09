#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
vector<int> adj[N];
int d[N], dp[N];
bool vis[N];
int n, m, t;

void dfs(int u) {
    vis[u] = 1;
    dp[u] = d[u];
    for (int v : adj[u]) {
        if (!vis[v] && d[u] < d[v]) dfs(v);

        if (d[u] < d[v]) dp[u] = min(dp[u], dp[v]);
        else dp[u] = min(dp[u], d[v]);
    }
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        memset(dp, 0, sizeof dp);
        memset(d, 0x3f, sizeof d);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }

        queue<int> q;
        d[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (d[v] > d[u] + 1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        dfs(1);
        for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
        cout << endl;
    }
}
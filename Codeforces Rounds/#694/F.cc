#include "bits/stdc++.h"

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int N = 3e5 + 10;
vector<int> adj[N];
bool color[N], vis[N];
int n, m, t;

void dfs(int u) {
    vis[u] = 1;
    bool hasTeacher = 0;
    for (int v : adj[u]) {
        if (color[v] == 1) hasTeacher = 1;
    }

    if (!hasTeacher) {
        color[u] = 1;
    }
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            vis[i] = 0;
            color[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) if (!vis[i]) ++cnt;
        if (cnt != 0) cout << "NO";
        else {
            cout << "YES" << endl;
            cout << count(color + 1, color + n + 1, 1) << endl;
            for (int i = 1; i <= n; ++i) {
                if (color[i] == 1) cout << i << ' ';
            }
        }
        cout << endl;
    }
}
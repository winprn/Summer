#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int N = 4e5 + 10;
vector<vector<int>> tmp;
vector<int> adj[N];
stack<int> q;
int ids[N], low[N], onStack[N], comp[N], in[N];
int n, m, ans = 0, nodes = 0, cur = 0, cnt = 0;

void dfs(int u) {
    q.push(u);
    ids[u] = low[u] = ++cnt;
    onStack[u] = 1;

    for (int v : adj[u]) {
        if (!ids[v]) dfs(v);
        if (onStack[v]) low[u] = min(low[u], low[v]);
    }

    if (low[u] == ids[u]) {
        tmp.pb({});
        while (!q.empty()) {
            int v = q.top();
            q.pop();
            onStack[v] = 0;
            comp[v] = (int) tmp.size() - 1;
            low[v] = ids[u];
            tmp.back().pb(v);
            if (v == u) break;
        }

        ++cur;
    }
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin >> n >> m;
    vector<vector<char>> a(n + 3, vector<char>(m + 3));
    vector<vector<int>> idx(n + 3, vector<int>(m + 3, 0));
    vector<int> need(m + 3);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                idx[i][j] = ++nodes;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) cout << a[i][j];
    //     cout << endl;
    // }
    for (int i = 0; i < m; ++i) cin >> need[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                if (i - 1 >= 0 && a[i - 1][j] == '#') adj[idx[i][j]].pb(idx[i - 1][j]);
                for (int k = i + 1; k < n; ++k) {
                    if (a[k][j] == '#') {
                        adj[idx[i][j]].pb(idx[k][j]);
                        break;
                    }
                }

                bool ok = 0, ok2 = 0;
                for (int k = i; k < n && (!ok || !ok2) && (a[k][j] != '#' || k == i); ++k) {
                    if (j - 1 >= 0 && a[k][j - 1] == '#' && !ok) {
                        adj[idx[i][j]].pb(idx[k][j - 1]);
                        ok = 1;
                    }
                    if (j + 1 < m && a[k][j + 1] == '#' && !ok2) {
                        adj[idx[i][j]].pb(idx[k][j + 1]);
                        ok2 = 1;
                    }
                }
            }
        }
    }

    tmp.pb({});
    for (int i = 1; i <= nodes; ++i) {
        if (!ids[i]) dfs(i);
    }

    for (int i = 1; i < (int) tmp.size(); ++i) {
        for (auto u : tmp[i]) {
            for (int v : adj[u]) {
                if (comp[v] != i) in[comp[v]]++;
            }
        }
    }

    cout << cur << endl;
    for (int i = 1; i < (int) tmp.size(); ++i) {
        // /cout << i << ' ' << in[comp[i]] << endl;
        ans += (in[i] == 0);
    }
    cout << ans << endl;
}
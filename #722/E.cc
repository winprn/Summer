#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define ms(a, x) memset(a, (x), sizeof a)

const int N = 3e5 + 10;
set<pair<int, int>> s;
vector<int> adj[N], adj2[N];
int st[N], ft[N];
int n, ans, t, cnt = 0;

int del(int u) {
    auto it = s.lower_bound({st[u], u});
    if (it != s.end() && ft[it->second] <= ft[u]) return -2;
    if (it == s.begin()) return -1;
    --it;

    int v = it->second;
    if (ft[v] < ft[u]) return -1;
    s.erase(it);
    return v;
}

void dfs1(int u, int p = -1) {
    st[u] = ++cnt;
    for (int v : adj2[u]) {
        if (v != p) dfs1(v, u);
    }
    ft[u] = cnt;
}

void dfs2(int u, int p = -1) {
    int cur = del(u);
    if (cur != -2) s.insert({st[u], u});
    ans = max(ans, (int) s.size());

    for (int v : adj[u]) {
        dfs2(v);
    }
    if (cur != -2) {
        s.erase({st[u], u});
        if (cur != -1) s.insert({st[cur], cur});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            adj2[i].clear();
            st[i] = ft[i] = 0;
        }
        ans = cnt = 0;

        for (int i = 2; i <= n; ++i) {
            int u; cin >> u;
            adj[u].pb(i);
        }
        for (int i = 2; i <= n; ++i) {
            int u; cin >> u;
            adj2[u].pb(i);
        }

        dfs1(1);
        dfs2(1);
        cout << ans << endl;
    }
}
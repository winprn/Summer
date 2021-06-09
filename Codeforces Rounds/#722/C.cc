#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
vector<int> adj[N];
int mn[N], mx[N];
int n, t;

pair<ll, ll> dfs(int u, int p) {
    ll a = 0, b = 0;
    for (int v : adj[u]) {
        if (v != p) {
            auto tmp = dfs(v, u);
            a += max(tmp.first + abs(mn[v] - mn[u]), tmp.second + abs(mx[v] - mn[u]));
            b += max(tmp.first + abs(mx[u] - mn[v]), tmp.second + abs(mx[v] - mx[u]));
        }
    }

    return {a, b};
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
            cin >> mn[i] >> mx[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto ans = dfs(1, -1);
        cout << max(ans.first, ans.second) << endl;
    }
}
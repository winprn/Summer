#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second

const int N = 305;
vector<pair<int, pair<int, int>>> edges;
int par[N];
int n, mn = 1e9, ans = 0;

int find(int u) {
    return (par[u] == -1 ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return 0;

    return par[u] = v, 1;
}

int main() {
    freopen("i", "r", stdin);

    cin >> n;
    par[n] = -1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        par[i] = -1;
        edges.push_back({x, {i, n}});
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w; cin >> w;
            if (i == j) continue ;
            edges.push_back({w, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    for (auto i : edges) {
        int u = i.se.fi, v = i.se.se;
        int w = i.fi;

        if (find(u) != find(v)) {
            join(u, v);
            ans += w;
        }
    }
    cout << ans;
}
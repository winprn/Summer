#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int par[N], sze[N];
int n, m, comp, mx;

int findP(int u) {
    return (par[u] == -1 ? u : par[u] = findP(par[u]));
}

bool join(int u, int v) {
    if ((u = findP(u)) == (v = findP(v))) return 0;

    return sze[v] += sze[u], par[u] = v, 1;
}

int main() {
    freopen("1676.inp", "r", stdin);
    freopen("1676.out", "w", stdout);

    cin >> n >> m;
    comp = n, mx = -1;
    memset(par, -1, sizeof par);
    for (int i = 1; i <= n; ++i) sze[i] = 1;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (findP(u) != findP(v)) {
            join(u, v);
            --comp;
            //cout << sze[findP(u)] << endl;
            mx = max(mx, sze[findP(u)]);
        }

        cout << comp << ' ' << mx << endl;
    }
}
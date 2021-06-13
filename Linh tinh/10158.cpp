#include "bits/stdc++.h"

using namespace std;

const int N = 2e4 + 10;
int par[N], en[N];
int n, c;

int find(int u) {
    return (par[u] == -1 ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return 0;

    return par[u] = v, 1;
}

int main() {
    freopen("10158.inp", "r", stdin);
    freopen("10158.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        en[i] = i + n;
        par[i] = par[i + n] = -1;
    }
    while (cin >> c, c) {
        int u, v; cin >> u >> v;
        if (c == 1) {
            if (find(en[u]) == find(v) || find(u) == find(en[v])) {
                cout << "-1" << endl;
            } else {
                join(u, v);
                join(en[u], en[v]);
            }
        } else if (c == 2) {
            if (find(u) == find(v) || find(en[u]) == find(en[v])) {
                cout << "-1" << endl;
            } else {
                join(u, en[v]);
                join(v, en[u]);
            }
        } else if (c == 3) {
            if (find(u) == find(v) || find(en[u]) == find(en[v])) cout << "1" << endl;
            else cout << "0" << endl;
        } else {
            if (find(u) == find(en[v]) || find(en[u]) == find(v)) cout << "1" << endl;
            else cout << "0" << endl;
        }
    }
}
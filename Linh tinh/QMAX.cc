#include "bits/stdc++.h"

using namespace std;

const int N = 1e6;
int st[8 * N];
int n, q;

void update(int id, int l, int r, int idx, int val) {
    if (idx < l || idx > r) return ;
    if (l == r) {
        st[id] = val;
        return ;
    }

    int m = (l + r) / 2;
    update(id * 2, l, m, idx, val);
    update(id * 2 + 1, m + 1, r, idx, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return INT_MIN;
    if (u <= l && v >= r) return st[id];

    int m = (l + r) / 2;
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        update(1, 0, n - 1, i, x);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int id, val;
            cin >> id >> val;
            --id;
            update(1, 0, n - 1, id, val);
        } else {
            int u, v; cin >> u >> v;
            --u, --v;
            cout << get(1, 0, n - 1, u, v) << ' ';
        }
    }
}
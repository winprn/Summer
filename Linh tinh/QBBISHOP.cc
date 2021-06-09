#include "bits/stdc++.h"

using namespace std;

const int td[4] = {-1, 1, -1, 1};
const int tc[4] = {-1, -1, 1, 1};
int d[205][205];
bool blocked[205][205], vis[205][205];
int n, m, si, sj, fi, fj, ans = 1e9;

bool ok(int i, int j) {
    return (i > 0 && i <= n && j > 0 && j <= n && !blocked[i][j]);
}

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m >> si >> sj >> fi >> fj;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        blocked[a][b] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) d[i][j] = 1e9;
    }
    queue<pair<int, int>> q;
    q.push({si, sj});
    d[si][sj] = 0, vis[si][sj] = 1;

    while (!q.empty()) {
        int ui = q.front().first;
        int uj = q.front().second;
        q.pop();

        if (ui == fi && uj == fj) break;
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= n; ++j) {
                int vi = ui + j * td[i];
                int vj = uj + j * tc[i];

                if (blocked[vi][vj]) break;
                if (ok(vi, vj) && !vis[vi][vj]) {
                    vis[vi][vj] = 1;
                    d[vi][vj] = d[ui][uj] + 1;
                    q.push({vi, vj});
                }
            }
        }
    }
    if (d[fi][fj] == 1e9) cout << "-1";
    else cout << d[fi][fj];
}
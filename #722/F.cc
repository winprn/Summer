#include "bits/stdc++.h"

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int N = 610;
long long a[N][N], d[N];
bool mark[N];
int n, m;

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m;
    ms(a, 0x3f);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
    }

    for (int i = 0; i < n; ++i) {
        ms(d, 0x3f), ms(mark, 0);
        for (int v = 0; v < n; ++v) {
            d[v] = min(d[v], a[i][v]);
        }

        while (1) {
            int v = -1;
            for (int j = 0; j < n; ++j) {
                if (!mark[j] && (v == -1 || d[v] > d[j])) {
                    v = j;
                }
            }
            if (v == -1) break;

            mark[v] = 1;
            d[(v + 1) % n] = min(d[(v + 1) % n], d[v] + 1);
            for (int u = 0; u < n; ++u) {
                d[(u + d[v]) % n] = min(d[(u + d[v]) % n], d[v] + a[v][u]);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (i == j) cout << "0 ";
            else cout << d[j] << ' ';
        }
        cout << endl;
    }
}
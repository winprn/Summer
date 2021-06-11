#include "bits/stdc++.h"

using namespace std;

#define ms(a, x) memset(a, (x), sizeof a)

const int N = 1e5 + 10;
int a[205], c[1005][1005], trace[1005], f[1005][1005];
bool isPrime[N];
int n, t, ans = 0;

void sieve() {
    ms(isPrime, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

bool bfs() {
    ms(trace, -1);
    queue<int> q;
    q.push(0);
    trace[0] = n + 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v) {
            if (trace[v] == -1 && c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == n) return 1;
                q.push(v);
            }
        }
    }

    return 0;
}

void inc() {
    int delta = 1e9, u = 0, v = n;
    do {
        u = trace[v];
        delta = min(delta, c[u][v] - f[u][v]);
        v = u;
    } while (v != 0);
    ans += delta;

    v = n;
    do {
        u = trace[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    } while (v != 0);
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    //sort(a + 1, a + n + 1);

    ms(c, 0), ms(f, 0);
    if (t == 1) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] & 1) continue ;
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue ;
                if ((a[i] + a[j]) & 1) {
                    c[i][j + n] = 1;
                }
            }
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (a[i] & 1) continue ;
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue ;
                if (isPrime[a[i] + a[j]]) {
                    c[i][j + n] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) c[0][i] = 1;
    for (int i = n + 1; i <= 2 * n; ++i) c[i][2 * n + 1] = 1;

    // for (int i = 0; i <= 2 * n + 1; ++i) {
    //     //cout << "U = " << i << ": ";
    //     for (int j = 0; j <= 2 * n + 1; ++j) {
    //         if (c[i][j] > 0) cout << "1,";
    //         else cout << "0,";
    //     }
    //     cout << endl;
    // }
    n = 2 * n + 1;

    while (bfs()) inc();
    cout << ans << endl;
}
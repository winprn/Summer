#include "bits/stdc++.h"

using namespace std;

const int N = 5e2 + 10;
vector<int> adj[N * N];
int a[N][N], b[N][N], ans[N][N];
bool mark[N * N];
int n, m, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n * m; ++i) {
            adj[i].clear();
            mark[i] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            int lst = -1;
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                mark[a[i][0]] = 1;
                if (j == 0) lst = a[i][j];
                else if (j > 0) {
                    assert(lst != -1);
                    adj[lst].push_back(a[i][j]);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            int idx = 0;
            for (int j = 0; j < n; ++j) {
                cin >> b[j][i];
                if (mark[b[j][i]]) {
                    ans[idx][0] = b[j][i];
                    ++idx;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int idx = 1;
            for (int j : adj[ans[i][0]]) {
                ans[i][idx] = j;
                ++idx;
            }
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << ans[i][j] << ' ';
            cout << endl;
        }
    }
}
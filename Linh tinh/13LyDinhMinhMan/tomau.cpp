#include "bits/stdc++.h"

using namespace std;

const string ans[3] = {"", "B", "R"};
const int N = 1005;
vector<int> adj[N];
int color[N];
bool vis[N];
int n, m;

int main() {
    freopen("tomau.inp", "r", stdin);
    freopen("tomau.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vis[1] = color[1] = 1;
    q.push({1, 1});
    while (!q.empty()) {
        int u = q.front().first;
        int mau = q.front().second;
        q.pop();

        for (int v : adj[u]) {
            color[v] = 3 - mau;
            if (!vis[v]) {
                vis[v] = 1;
                q.push({v, color[v]});
            }
        }
    }

    bool ok = 1;
    for (int i = 1; i <= n && ok; ++i) {
        for (int j : adj[i]) {
            if (color[i] == color[j]) {
                ok = 0;
                break;
            }
        }
    }

    if (!ok) cout << "-1";
    else {
        cout << "1" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << ans[color[i]];
        }
        cout << endl;
    }
}
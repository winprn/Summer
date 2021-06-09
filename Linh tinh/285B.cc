#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int a[N];
bool vis[N];
int n, s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> n >> s >> t;
    --s, --t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    int cnt = 0;
    vis[s] = 1;
    while (s != t) {
        s = a[s];
        if (vis[s]) break;

        vis[s] = 1;
        ++cnt;
    }

    if (vis[t]) cout << cnt;
    else cout << "-1";
}
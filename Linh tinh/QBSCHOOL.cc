#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef long long ll;

const int N = 1e5 + 10;
vector<pair<ll, ll>> adj[N];
ll d[N], dp[N];
ll n, m;

void dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    d[1] = 0, dp[1] = 1;

    while (!pq.empty()) {
        ll u = pq.top().se;
        ll uw = pq.top().fi;
        pq.pop();

        if (uw > d[u]) continue ;
        for (auto i : adj[u]) {
            ll v = i.fi;
            ll w = i.se;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                dp[v] = dp[u];
                pq.push({d[v], v});
            } else if (d[v] == d[u] + w) dp[v] += dp[u];
        }
    }
}

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i <= n; ++i) d[i] = 1e18;
    for (int i = 0; i < m; ++i) {
        ll t, u, v, w;
        cin >> t >> u >> v >> w;
        adj[u].pb({v, w});
        if (t == 2) adj[v].pb({u, w});
    }

    dijkstra();
    cout << d[n] << ' ' << dp[n] << endl;
}
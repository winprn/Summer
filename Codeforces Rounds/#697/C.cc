#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
vector<int> edges[N];
int cnt[N], cnt2[N];
int n, m, k, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        memset(cnt2, 0, sizeof cnt);
        cin >> n >> m >> k;
        for (int i = 0; i < k; ++i) edges[i].clear();
        for (int i = 0; i < k; ++i) {
            int x; cin >> x;
            cnt[x]++;
            edges[i].push_back(x);
        }
        for (int i = 0; i < k; ++i) {
            int x; cin >> x;
            cnt2[x]++;
            edges[i].push_back(x);
        }
    
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            int u = edges[i][0], v = edges[i][1];
            ans += k - cnt[u] - cnt2[v] + 1;
        }
        cout << ans / 2 << endl;
    }
}
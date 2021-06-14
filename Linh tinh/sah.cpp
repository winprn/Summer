#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

vector<pair<ll, ll>> a, b;
ll n, k;

vector<pair<int, pair<ll, ll>>> get(bool cur, vector<pair<ll, ll>> x) {
    vector<pair<int, pair<ll, ll>>> ans;
    for (int i = 0; i < (1<<(int) x.size()); ++i) {
        ll tmp = 0, h = -1;
        int idx = -1;
        bool ok = 1;
        for (int j = 0; j < (int) x.size(); ++j) {
            if (i & (1<<j)) {
                if (idx == -1) {
                    idx = j;
                    h = x[j].fi;
                    tmp = x[j].se;
                } else if (h <= x[j].fi) {
                    idx = j;
                    if (cur) h = min(h, x[j].fi);
                    else h = max(h, x[j].fi);
                    tmp += x[j].se;
                } else {ok = 0; break;}
            }
        }

        if (ok && idx != -1) ans.pb({idx, {h, tmp}});
    }

    return ans;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin >> n >> k;
    a.resize(n / 2), b.resize(n - n / 2);
    for (int i = 0; i < (int) a.size(); ++i) cin >> a[i].fi >> a[i].se;
    //for (auto i : a) cout << i.fi << ' ' << i.se << endl;
    for (int i = 0; i < (int) b.size(); ++i) cin >> b[i].fi >> b[i].se;
    auto l = get(0, a), r = get(1, b);
    sort(l.begin(), l.end()), sort(r.begin(), r.end());

    for (auto i : l) cout << i.se.fi << ' ' << i.se.se << endl;
    for (auto i : r) cout << i.se.fi << ' ' << i.se.se << endl;
    // for (auto i : r) cout << i.fi << ' ' << i.se << endl;

    ll ans = 0;
    for (auto i : l) {
        int j = 0;
        while (j < (int) r.size() && i.se.se + r[j].se.se < k) ++j;
        while (j < (int) r.size() && i.se.fi > r[j].se.fi) ++j;

        ans += (int) r.size() - j;
    }
    for (int i = 0; i < (int) l.size(); ++i) {
        if (l[i].se.se >= k) {ans += (int) l.size() - i; break;}
    }
    for (int i = 0; i < (int) r.size(); ++i) {
        if (r[i].se.se >= k) {ans += (int) r.size() - i; break;}
    }
    cout << ans << endl;
}
#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second


const int N = 2e5 + 10;
pair<pair<int, int>, int> a[N];
pair<int, int> w[N], h[N];
int ans[N];
int n, t;

int get(int H, int W) {
    int l = -1, r = n;
    // while (r - l >= 0) {
    //     int m = (l + r) / 2;
    //     if (w[m].fi > W && h[w[m].se].fi > H) return w[m].se;
    //     else if (w[m].fi > H && h[w[m].se].fi > W) return w[m].se;
    //     else if (h[m].fi > H && w[h[m].se].fi > W) return h[m].se;
    //     else if (h[m].fi > W && w[h[m].se].fi > H) return h[m].se;
    //     else l = m + 1;
    // }

    while (r - l > 0) {
        int m = (l + r) / 2;
        if (H == 4 && W == 7) cout << "#" << m << endl;
        if (a[m].fi.fi < H && a[m].fi.se < W) return a[m].se;
        else if (a[m].fi.fi < W && a[m].fi.se < H) return a[m].se;
        else if (a[m].fi.fi >= H) r = m - 1;
        else l = m + 1;
    }

    // for (int i = 0; i < n; ++i) {
    //     if (a[i].fi.fi < H && a[i].fi.se < W) return a[i].se;
    //     else if (a[i].fi.fi < W && a[i].fi.se < H) return a[i].se;
    // }

    return -1;
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.fi.fi == b.fi.fi) return a.fi.se < b.fi.se;

    return a.fi.fi < b.fi.fi;
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        set<pair<int, int>> s;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; ++i) {
            ans[i] = -2;
            cin >> h[i].fi >> w[i].fi;
            a[i] = {{h[i].fi, w[i].fi}, i};
            s.insert({h[i].fi, w[i].fi});
            mp[a[i].fi] = i;
            //a[i] = {h[i].fi, w[i].fi};
            h[i].se = w[i].se = i;
        }
        // sort(a, a + n, cmp);
        // sort(h, h + n), sort(w, w + n);
        // for (int i = 0; i < n; ++i) cout << h[i].fi << ' ';
        // cout << endl;
        // for (int i = 0; i < n; ++i) cout << w[i].fi << ' ';
        // cout << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << a[i].fi.fi << ' ' << a[i].fi.se << endl;
        // }
        // cout << endl;

        for (int i = 0; i < n; ++i) {
            //int id = get(a[i].fi.fi, a[i].fi.se);
            auto it = s.upper_bound({a[i].fi.fi, a[i].fi.se});
            if (it != s.end()) {
                cout << a[i].fi.fi << ' ' << a[i].fi.se << ' ' << it->fi << ' ' << it->se << endl;
                if (it->fi > a[i].fi.fi && it->se > a[i].fi.se) {
                    ans[mp[{it->fi, it->se}]] = i;
                } else if (it->fi > a[i].fi.se && it->se > a[i].fi.fi) {
                    ans[mp[{it->fi, it->se}]] = i;
                } else {
                    it = s.upper_bound({it->fi, it->se});
                    if (it != s.end()) {
                        if (it->fi > a[i].fi.fi && it->se > a[i].fi.se) {
                            ans[mp[{it->fi, it->se}]] = i;
                        } else if (it->fi > a[i].fi.se && it->se > a[i].fi.fi) {
                            ans[mp[{it->fi, it->se}]] = i;
                        }
                    }
                }
            }
            // if (id != -1) {
            //     ans[a[i].se] = id;
            // }
        }

        for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
        cout << endl;
    }
}
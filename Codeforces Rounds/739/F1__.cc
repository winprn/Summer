#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#else
#define dbg(...) {/* nop; */}
#endif

// F cin/cout
#define cin nullptr
#define cout nullptr

#define MONKE 0

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;

vector<int> digitify(int n) {
    vector<int> rc;

    while (n != 0) {
        rc.push_back(n % 10);
        n /= 10;
    }

    reverse(begin(rc), end(rc));

    return rc;
};

vector<int> n_digits, ans;
int k;

int dp[10][1024][2];

bool func(int idx, int dmask, bool bigger) {
    if (idx == n_digits.size())
        return __builtin_popcount(dmask) <= k;

    if (dp[idx][dmask][bigger] != -1)
        return dp[idx][dmask][bigger];

    int lo = n_digits[idx];
    int hi = 9;

    if (bigger)
        lo = 0;

    for (int d = lo; d <= hi; d ++) {
        if (func(idx + 1, dmask | (1 << d), bigger or (d > lo))) {
            ans[idx] = d;
            return true;
        }
    }

    dp[idx][dmask][bigger] = false;

    return false;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
    int t;
    scanf("%d", &t);

    while (t--) {
        memset(dp, -1, sizeof(dp));

        int n;
        scanf("%d %d", &n, &k);

        n_digits = digitify(n);
        ans.resize(n_digits.size(), 0);

        dbg(n_digits);

        bool rc = func(0, 0, false);

        assert(rc);

        for (int d : ans)
            printf("%d", d);
        puts("");
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return MONKE;
}


#include "bits/stdc++.h"

using namespace std;

string s;
int n, k, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int fst = -1, lst = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                fst = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '*') {
                lst = i;
                break;
            }
        }
        assert(fst != -1 && lst != -1);

        if (fst == lst) cout << 1;
        else if (lst - fst <= k) cout << 2;
        else {
            int ans = 2, cur = fst;
            for (int i = fst; i < n; ++i) {
                while (i - cur < k && i < n) ++i;
                while (s[i] != '*') --i;
                if (i != lst) ++ans;

                if (lst - i <= k) break;
                cur = i;
            }
            cout << ans;
        }
        cout << endl;
    }
}
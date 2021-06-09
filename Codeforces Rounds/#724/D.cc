#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        set<int> s;
        bool ok = 1;
        s.insert(a[1]);
        for (int i = 2; i <= n; ++i) {
            int prv = a[i - 1];
            if (prv < a[i]) {
                auto it = s.upper_bound(prv);
                if (it != s.end() && *it < a[i]) {
                    ok = 0;
                    break;
                }
            }
            if (prv > a[i]) {
                auto it = s.lower_bound(prv);
                if (it != s.begin() && *(--it) > a[i]) {
                    ok = 0;
                    break;
                }
            }
            s.insert(a[i]);
        }
        if (ok) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
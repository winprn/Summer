#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (x) * (x)

int n, t, pr1, pr2;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        pr1 = pr2 = -1;
        cin >> n;
        for (int i = n + 1; ; ++i) {
            bool ok = 1;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {pr1 = i; break;}
        }

        for (int i = pr1 + n; ; ++i) {
            bool ok = 1;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    ok = 0; 
                    break;
                }
            }

            if (ok) {pr2 = i; break;}
        }

        assert(pr1 != -1);
        assert(pr2 != -1);
        long long ans1 = pr1 * 1LL * sqr(pr1);
        long long ans2 = pr1 * 1LL * pr2;

        cout << min(ans1, ans2) << endl;
    }
}
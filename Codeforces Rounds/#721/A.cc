#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long t, n, ans;

int main() {
    freopen("i", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) cout << 1 << endl;
        else {
            for (long long i = 0; i <= 32; ++i) {
                if ((1 << i) > n) {
                    ans = i - 1;
                    break;
                } else if ((1 << i) == n) {ans = i; break;}
            }

            cout << (1 << ans) - 1 << endl;
        }
    }
}

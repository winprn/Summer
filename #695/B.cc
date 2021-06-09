#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int a[N];
bool ok[N];
int n, t, total;

bool isHill(int i) {
    return (i > 1 && i < n && a[i] > a[i - 1] && a[i] > a[i + 1]);
}

bool isValley(int i) {
    return (i > 1 && i < n && a[i] < a[i - 1] && a[i] < a[i + 1]);
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        memset(ok, 0, sizeof ok);
        total = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 2; i <= n - 1; ++i) {
            if (isHill(i) || isValley(i)) {
                ok[i] = 1;
                ++total;
            }
        }

        int ans = total;
        for (int i = 2; i <= n - 1; ++i) {
            int tmp = a[i];
            a[i] = a[i - 1];
            ans = min(ans, total - ok[i] - ok[i - 1] - ok[i + 1] + isHill(i) + isHill(i - 1) + isHill(i + 1) + isValley(i) + isValley(i - 1) + isValley(i + 1));
            a[i] = a[i + 1];
            ans = min(ans, total - ok[i] - ok[i - 1] - ok[i + 1] + isHill(i) + isHill(i - 1) + isHill(i + 1) + isValley(i) + isValley(i - 1) + isValley(i + 1));
            a[i] = tmp;
        }

        cout << ans << endl;
    }
}
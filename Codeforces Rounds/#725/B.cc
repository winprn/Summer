#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % n != 0) cout << "-1" << endl;
        else {
            int tmp = sum / n, need = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] < tmp) need += (tmp - a[i]);
            }
            sort(a, a + n, greater<int>());

            int cur = 0, ans = 0;
            for (int i = 0; i < n && cur != need; ++i) {
                if (a[i] > tmp) cur += (a[i] - tmp);
                ++ans;
            }
            cout << ans << endl;
        }
    }
}
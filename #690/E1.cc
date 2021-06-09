#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 10;
long long cnt[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n + 5; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
        }

        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] && cnt[i + 1] && cnt[i + 2]) ans += cnt[i] * cnt[i + 1] * cnt[i + 2];
            if (cnt[i] && cnt[i + 1] >= 2) ans += cnt[i] * ((cnt[i + 1] * (cnt[i + 1] - 1)) / 2);
            if (cnt[i] && cnt[i + 2] >= 2) ans += cnt[i] * ((cnt[i + 2] * (cnt[i + 2] - 1)) / 2);
            if (cnt[i] >= 2 && cnt[i + 1]) ans += ((cnt[i] * (cnt[i] - 1)) / 2) * cnt[i + 1];
            if (cnt[i] >= 2 && cnt[i + 2]) ans += ((cnt[i] * (cnt[i] - 1)) / 2) * cnt[i + 2];
            if (cnt[i] >= 3) ans += ((cnt[i] * (cnt[i] - 1) * (cnt[i] - 2)) / 6);
        }
        cout << ans << endl;
    }
}
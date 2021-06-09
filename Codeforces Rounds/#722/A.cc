#include "bits/stdc++.h"

using namespace std;

const int N = 1e2 + 10;
int a[N], cnt[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        cout << n - cnt[*min_element(a, a + n)] << endl;
    }
}
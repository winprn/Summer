#include "bits/stdc++.h"

using namespace std;

int n;

bool ok(long long x) {
    int cnt = 0;
    for (int i = 1; 1LL * i * i <= x; ++i) {
        if (x % i == 0) {
            ++cnt;
            if (x / i != i) ++cnt;
        }
    }

    return cnt == 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        if (ok(x)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
#include "bits/stdc++.h"

using namespace std;

int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        map<pair<int, int>, int> mark;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            char x; cin >> x;
            if (x == 'D') ++cnt1;
            else ++cnt2;
            int g = __gcd(cnt1, cnt2);

            cout << ++mark[{cnt1/g, cnt2/g}] << ' ';
        }
        cout << endl;
    }
}
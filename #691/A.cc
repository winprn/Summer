#include "bits/stdc++.h"

using namespace std;

const int N = 1e3 + 10;
int a[N], b[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            char x; cin >> x;
            a[i] = x - '0';
        }
        for (int i = 0; i < n; ++i) {
            char x; cin >> x;
            b[i] = x - '0';
        }

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) ++cnt1;
            else if (b[i] > a[i]) ++cnt2;
        }

        if (cnt1 > cnt2) cout << "RED";
        else if (cnt2 > cnt1) cout << "BLUE";
        else cout << "EQUAL";
        cout << endl;
    }
}
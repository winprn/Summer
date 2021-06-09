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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n, greater<int>());

        long long A = 0, B = 0;
        bool cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                if (cnt) A += a[i];
            } else if (a[i] % 2 != 0) {
                if (!cnt) B += a[i];
            }

            cnt = !cnt;
        }

        if (A == B) cout << "Tie";
        else if (A > B) cout << "Alice";
        else cout << "Bob";
        cout << endl;
    }
}
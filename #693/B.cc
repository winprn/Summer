#include "bits/stdc++.h"

using namespace std;

int a[105];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n, greater<int>());

        int A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            if (A <= B) A += a[i];
            else B += a[i];
        }

        if (A == B) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
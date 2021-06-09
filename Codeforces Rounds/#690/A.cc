#include "bits/stdc++.h"

using namespace std;

const int N = 305;
int a[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> ans;
        int l = 0, r = n - 1;
        bool ok = 1;
        while ((int) ans.size() < n) {
            if (ok) {
                ans.push_back(a[l]);
                ++l;
            } else {
                ans.push_back(a[r]);
                --r;
            }

            ok = !ok;
        }
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
}
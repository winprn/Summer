#include "bits/stdc++.h"

using namespace std;

int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n > 45) cout << "-1";
        else {
            bool used[15];
            memset(used, 0, sizeof used);
            int sum = 0, i = 9;
            while (sum != n) {
                while (used[i] || sum + i > n) --i;

                sum += i;
                used[i] = 1;
                i = 9;
            }

            for (int i = 1; i <= 9; ++i) if (used[i]) cout << i;
        }
        cout << endl;
    }
}
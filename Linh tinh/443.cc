#include "bits/stdc++.h"

using namespace std;

void get() {
    for (int i = 0; i <= 11; ++i) {
        for (int j = 0; j <= 13; ++j) {
            for (int k = 0; k <= 19; ++k) {
                for (int l = 0; l <= 32; ++l) {
                    ll tmp = pw(7, i), tmp2 = pw(5, j), tmp3 = pw(3, k), tmp4 = pw(2, l);
                    if (tmp * tmp2 <= MX) ans.pb(tmp * tmp2);
                    if (tmp * tmp3 > MX) ans.pb(tmp * tmp3);
                    if (tmp * tmp4 > MX) ans.pb(tmp * tmp4);
                    if (tmp2 * tmp3 > MX) ans.pb(tmp2 * tmp3);
                    if (tmp2 * tmp4 > MX) ans.pb(tmp2 * tmp4);
                    if (tmp3 * tmp4 > MX) ans.pb(tmp3 * tmp4);
                    if (tmp * tmp2 * tmp3 <= MX) ans.pb(tmp * tmp2 * tmp3);
                    if (tmp * tmp2 * tmp4 <= MX) ans.pb(tmp * tmp2 * tmp4);
                }
            }
        }
    }
}

int main() {
    get();

    while (cin >> n, n) {
        cout << "The " << ' ' << n;
        if (n % 10 == 1) cout << "st";
        else if (n % 10 == 2) cout << "nd";
        else if (n % 10 == 3) cout << "rd";
        else cout << "th";

        cout << " humble number is " << a[n] << '.' << endl;
    }
}
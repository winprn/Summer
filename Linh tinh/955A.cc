#include "bits/stdc++.h"

using namespace std;

int h, m, cur, d, cost, n;

int main() {
    cout.precision(4);
    cout << fixed;
    freopen("i", "r", stdin);

    cin >> h >> m;
    cin >> cur >> d >> cost >> n;

    int delta = 0;
    if (h < 20) delta = (20 - h) * 60 - m;
    long long wait = cur + delta * d;

    double ans = 0, ans2 = 0;
    while (cur > 0) {
        cur -= n;
        if (m == 60) {
            ++h;
            m = 0;
        }
        ans += cost;

        ++m;
    }

    while (wait > 0) {
        wait -= n;
        ans2 = ans2 + cost;
    }

    cout << min(ans, ans2 * .8) << endl;
}
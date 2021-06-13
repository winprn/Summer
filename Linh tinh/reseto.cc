#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

bitset<(int)1e7 + 10> pr;
int n, k, cnt = 0;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin >> n >> k;
    pr.set();
    for (int i = 2; i <= n; ++i) {
        if (pr[i]) {
            cnt++;
            if (cnt == k) {
                cout << i << endl;
                break;
            }
            int ans = -1;
            for (int j = 2 * i; j <= n; j += i) {
                if (pr[j]) ++cnt;
                pr[j] = 0;
                if (cnt == k) {ans = j; break;}
            }

            if (ans != -1) {cout << ans << endl; break;}
        }
    }
}
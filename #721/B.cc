#include <bits/stdc++.h>

using namespace std;

string s;
int n, t, cnt0, cnt1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cnt0 = cnt1 = 0;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) cnt0 += s[i] == '0';

        bool palin = 1;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1]) palin = 0;
            if ((s[i] == '1' || s[n - i - 1] == '1') && s[i] != s[n - i - 1]) ++cnt1;
        }

        if (palin) {
            if (cnt0 == 1 || cnt0 % 2 == 0) cout << "BOB";
            else cout << "ALICE";
        } else {
            if (cnt0 == 2 && cnt1 == 1) cout << "DRAW";
            else cout << "ALICE";
        }

        cout << endl;
    }
}

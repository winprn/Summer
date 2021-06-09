#include "bits/stdc++.h"

using namespace std;

int main() {
    freopen("i", "r", stdin);

    string s; cin >> s;
    const int n = (int) s.size();
    int lst = -1;
    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0) lst = i;
    }

    for (int i = 0; i < n; ++i) {
        if ((s[i] - '0') % 2 == 0 && s[i] < s[n - 1]) {
            lst = i;
            break;
        }
    }

    if (lst == -1) cout << "-1";
    else {
        swap(s[lst], s[n - 1]);
        cout << s;
    }
}
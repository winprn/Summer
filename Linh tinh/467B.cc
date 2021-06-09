#include "bits/stdc++.h"

using namespace std;

const int N = 1e3 + 10;
string a[N], player;
int n, m, k;

string converse(int x) {
    string kq = "";
    while (x) {
        int tmp = x % 2;
        char c = '0' + tmp;
        kq.push_back(c);
        x /= 2;
    }
    int tmp = x % 2;
    char c = '0' + tmp;
    kq.push_back(c);
    reverse(kq.begin(), kq.end());

    return kq;
}

bool ok(string s) {
    while ((int) player.size() < (int) s.size()) {
        player = '0' + player;
    }
    while ((int) player.size() > (int) s.size()) {
        s = '0' + s;
    }

    int cnt = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] != player[i]) ++cnt;
    }

    return cnt <= k;
}

int main() {
    freopen("i", "r", stdin);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        a[i] = converse(x);
    }
    int tmp; cin >> tmp;
    player = converse(tmp);

    int ans = 0;
    for (int i = 0; i < m; ++i) ans += ok(a[i]);
    cout << ans << endl;
}
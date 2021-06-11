#include "bits/stdc++.h"

using namespace std;

int n, m, t;

int get(int n) {
    long long ans = 0;
    string tmp = to_string(n);
    for (int i = 1; i <= tmp.size(); ++i) {
        ans += n / pow(10, i - 1);
    }

    return ans;
}

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << get(m) - get(n) << endl;
    }
}
#include "bits/stdc++.h"

using namespace std;

int main() {
    freopen("i", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    while (m--) {
        n = (int) a.size();
        //cout << a.size() << endl;
        int idx = (n + 1) / 2;
        --idx;
        cout << a[idx] << ' ';
        a.erase(a.begin() + idx);
    }
}
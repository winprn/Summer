#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
pair<int, int> match[N];
int a[N], b[N], home[N], away[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        home[a[i]]++, away[b[i]]++;
        match[i] = {n - 1, n - 1};
    }

    for (int i = 0; i < n; ++i) {
        match[i].first += home[b[i]];
        match[i].second -= home[b[i]];
    }

    for (int i = 0; i < n; ++i) {
        cout << match[i].first << ' ' << match[i].second << endl;
    }
}
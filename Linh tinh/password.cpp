#include "bits/stdc++.h"

using namespace std;

const int N = 2e4 + 10;
string s[N];
long long n, ans = 0;

int main() {
    freopen("password.inp", "r", stdin);
    freopen("password.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    
    unordered_map<string, long long> cnt;
    for (int i = 0; i < n; ++i) {
        set<string> st;
        for (int j = 0; j < (int) s[i].size(); ++j) {
            string cur = "";
            for (int k = j; k < (int) s[i].size(); ++k) {
                cur += s[i][k];
                st.insert(cur);
            }
        }

        for (auto x : st) cnt[x]++;
    }

    for (int i = 0; i < n; ++i) {
        long long tmp = cnt[s[i]];
        ans += (tmp - 1);
    }
    cout << ans << endl;
}
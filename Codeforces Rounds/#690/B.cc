#include "bits/stdc++.h"

using namespace std;

#define pb push_back

string s;
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> s;
        string tmp = "", tmp2 = "";
        tmp.pb(s[0]), tmp.pb(s[1]), tmp.pb(s[2]), tmp.pb(s[3]);
        tmp2.pb(s[n - 4]), tmp2.pb(s[n - 3]), tmp2.pb(s[n - 2]), tmp2.pb(s[n - 1]);
        if (tmp == "2020" || tmp2 == "2020") cout << "YES";
        else {
            bool ok = 0;
            if (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ok = 1;
            if (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ok = 1;
            if (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') ok = 1;

            if (ok) cout << "YES";
            else cout << "NO";
        }
        cout << endl;
    }
}
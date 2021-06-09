#include "bits/stdc++.h"

using namespace std;

string s;
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n >> s;
        unordered_map<string, bool> mark;
        for (int i = 0; i < n; ++i) {
            string cur = "";
            cur += s[i];
            mark[cur] = 1;
            
            if (i < n - 1) {
                cur += s[i + 1];
                mark[cur] = 1;
            }
            if (i < n - 2) {
                cur += s[i + 2];
                mark[cur] = 1;
            }
        }

        string ans = "";
        bool ok = 0;
        for (int i = 0; i < 26 && !ok; ++i) {
            string tmp = "";
            tmp += ('a' + i);
            //cout << tmp << endl;
            if (!mark[tmp]) {
                ans = tmp;
                ok = 1;
                break;
            }
        }
        for (int i = 0; i < 26 && !ok; ++i) {
            for (int j = 0; j < 26 && !ok; ++j) {
                string tmp = "";
                tmp += ('a' + i);
                tmp += ('a' + j);
                //cout << tmp << endl;
                if (!mark[tmp]) {
                    ans = tmp;
                    ok = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < 26 && !ok; ++i) {
            for (int j = 0; j < 26 && !ok; ++j) {
                for (int k = 0; k < 26 && !ok; ++k) {
                    string tmp = "";
                    tmp += ('a' + i);
                    tmp += ('a' + j);
                    tmp += ('a' + k);
                    //cout << tmp << endl;
                    if (!mark[tmp]) {
                        ans = tmp;
                        ok = 1;
                        break;
                    }
                }
            }
        }
        assert(ans != "");
        //cout << mark["ac"] << endl;
        cout << ans << endl;
    }
}
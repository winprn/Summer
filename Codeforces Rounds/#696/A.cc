#include <bits/stdc++.h>

using namespace std;

#define pb push_back

string a, b;
int n, t, lst;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        a.clear();
        cin >> n >> b;
        lst = -1;
        for (int i = 0; i < n; ++i) {
            if (b[i] == '0') {
                if (lst == 1) {
                    a.pb('0');
                    lst = 0;
                } else {
                    a.pb('1');
                    lst = 1;
                }
            } else {
                if (lst != 2) {
                    a.pb('1');
                    lst = 2;
                } else {
                    a.pb('0');
                    lst = 1;
                }
            }
        }
        cout << a << endl;
    }
}
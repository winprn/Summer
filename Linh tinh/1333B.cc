#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
bool ok1[N], ok2[N];
int n, t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i == 0) continue ;
            else ok1[i] = (a[i - 1] < 0 || ok1[i - 1]), ok2[i] = (a[i - 1] > 0 || ok2[i - 1]);
        }

        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            //cout << "!" << a[i] << ' ' << b[i] << endl;
            if (a[i] == b[i]) continue ;
            else if (i == 0 && a[i] != b[i]) {
                ok = 0;
            }
            
            if (a[i] < b[i] && ok2[i] == 0) {
                ok = 0;
            }
            if (a[i] > b[i] && ok1[i] == 0) {
                ok = 0;
            }
        }

        if (ok) cout << "YES";
        else cout << "NO";
        cout << endl; 
    }
}
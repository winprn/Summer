#include <bits/stdc++.h>

using namespace std;

long long n;
int t;

int main() {
    freopen("i", "r", stdin);

    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 1) cout << "YES";
        else {
            while (n != 1 && n % 2 == 0) {
                n /= 2;
            }

            if (n == 1) cout << "NO";
            else cout << "YES";
        }
        cout << endl;
    }
}
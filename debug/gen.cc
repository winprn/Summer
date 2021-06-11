#include "bits/stdc++.h"

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 50; ++i) {
        ofstream inp("i");
        int n = Rand(2, 200), t = Rand(1, 2);
        inp << n << ' ' << t << endl;
        for (int i = 0; i < n; ++i) {
            inp << Rand(300, 500) << endl;
        }
        inp.close();

        system("box.exe");
        system("box_ac.exe");
        if (system("fc o ans") != 0) {
            cout << "WA" << endl;
            return 0;
        }
    }

    cout << "ok(?)" << endl;
    return 0;
}
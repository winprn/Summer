#include "bits/stdc++.h"

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

int main() {
    srand(time(0));
    for (int i = 10000; i <= 100000; ++i) {
        ofstream inp("i");
        inp<<i<<endl;
        inp.close();

        ofstream out("log");
        system("ac.exe");
        system("wa.exe");
        if (system("fc o ans") != 0) {
            out << "WA" << endl;
            return 0;
        }
    }

    cout << "ok(?)" << endl;
    return 0;
}
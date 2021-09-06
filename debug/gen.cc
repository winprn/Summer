#include "bits/stdc++.h"

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

const string cmd[4]={"UP","DOWN","LEFT","RIGHT"};
const char c[2]={'.','#'};

long long Rand(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

int main() {
    srand(time(0));
    for (int i = 1; i <= 100; ++i) {
        ofstream inp("i");
        int n=Rand(70,100);
        inp<<n<<endl;
        for(int i=0;i<n;++i){
            int tmp=Rand(1,2000);
            inp<<tmp<<' ';
        }
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

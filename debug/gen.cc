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
    for (int i = 1; i <= 20; ++i) {
        ofstream inp("i");
        map<int,bool> mark;
        int n=Rand(1,20);
        inp<<n<<endl;
        for(int i=0;i<n;++i){
            int cur=Rand(1,2*n);
            while(mark[cur])cur=Rand(1,2*n);

            inp<<cur<<' ';
            mark[cur]=1;
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
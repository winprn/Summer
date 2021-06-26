#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef double ld;

const ld EPS=1e-9;
ld d,s;

void get(ld x){
    cout<<x+s-x*cosh(d/(2*x));
}

int main() {
    cout.precision(9);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>d>>s;
    get(125000.166665);

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
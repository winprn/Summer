#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll a,b;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>a>>b;
    ll lcm=a/__gcd(a,b)*b;

    int aa=lcm/a,bb=lcm/b;
    if(a>b)++aa;
    else ++bb;

    if(aa<bb)cout<<"Masha";
    else if(aa>bb)cout<<"Dasha";
    else cout<<"Equal";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}